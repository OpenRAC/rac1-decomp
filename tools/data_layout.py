#!/usr/bin/env python3
"""Link the PAL executable's initialized data from its compiled input sections."""
import re
from collections import defaultdict
from pathlib import Path

import core_rodata
import data_in_c
import jump_tables

EXE_LABEL = re.compile(r"^(?:D|jtbl)_[0-9A-F]{8}$")
LAYOUT_SYMBOL = "__rac1_compiled_data_layout"
LAYOUT_VERSION = 1

# The retail linker uses a different layout at these two boundaries.
# kprintf's first switch table ends in CD fill. The data after init_once's
# switch table starts on a 16-byte boundary despite its weaker input alignment.
ALIGN_BEFORE = {
    0x001529E0: (16, 0xCD),
    0x001E7E80: (16, 0),
}


def compiled_data() -> list[tuple[str, str, int]]:
    """(object, input section, retail address), in link order."""
    sections = [(obj, section, data_in_c.address(labels[0]))
                for obj, section, labels in core_rodata.sections()]
    sections.extend((obj, f".rodata.{label}", data_in_c.address(label))
                    for label, _, obj in jump_tables.provided() if EXE_LABEL.fullmatch(label))
    sections.extend((obj, section, data_in_c.address(label))
                    for segment in data_in_c.SEGMENTS for label, obj, section in data_in_c.provided(segment))
    return sorted(sections, key=lambda piece: piece[2])


def linker_inputs(directory: Path) -> None:
    """Write the contents of each initialized output section for rac1.ld.sh."""
    sections: dict[str, list[str]] = {segment: [] for segment in data_in_c.SEGMENTS}
    aliases = defaultdict(list)
    for name, owner in sorted(data_in_c.interior().items()):
        offset = data_in_c.address(name) - data_in_c.address(owner)
        aliases[owner].append(f"    {name} = {owner} + 0x{offset:X};")
    for obj, section, address in compiled_data():
        label = f"D_{address:08X}"
        lines = sections[data_in_c.segment_of(label)]
        if address in ALIGN_BEFORE:
            alignment, fill = ALIGN_BEFORE[address]
            if fill:
                lines.append(f"    FILL(0x{fill:02X}{fill:02X});")
            lines.append(f"    . = ALIGN({alignment});")
            if fill:
                lines.append("    FILL(0);")
        lines.append(f"    {obj}({section})")
        lines.extend(aliases[label])
    directory.mkdir(parents=True, exist_ok=True)
    for segment, lines in sections.items():
        (directory / f"{segment}.ld").write_text("\n".join(lines) + "\n", newline="\n")


def padding_ranges(inputs: list[tuple[int, int, int]]) -> list[tuple[int, int, int]]:
    """Expected (address, length, byte) of the linker fill between compiled inputs."""
    cursors = {segment: start for segment, (_, start, _, _) in data_in_c.SEGMENTS.items()}
    ranges = []
    last_end = 0
    for address, size, alignment in inputs:
        if address < last_end:
            raise ValueError(f"compiled data sections overlap at {address:#x}")
        segment = data_in_c.segment_of(f"D_{address:08X}")
        cursor = cursors[segment]
        explicit, fill = ALIGN_BEFORE.get(address, (1, 0))
        aligned = cursor + (-cursor % explicit)
        placed = aligned + (-aligned % max(1, alignment))
        if placed != address:
            raise ValueError(f"data section would link at {placed:#x}, expected {address:#x}")
        if aligned != cursor:
            ranges.append((cursor, aligned - cursor, fill))
        if placed != aligned:
            ranges.append((aligned, placed - aligned, 0))
        last_end = placed + size
        cursors[segment] = last_end
    return ranges


if __name__ == "__main__":
    linker_inputs(Path("build-sn/data-link"))
    # Outside the output sections, the legacy linker emits an absolute version value.
    print(f"  {LAYOUT_SYMBOL} = {LAYOUT_VERSION};")
