import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import data_layout


class DataLayoutTest(unittest.TestCase):
    def test_alignment_uses_the_input_section_alignment(self):
        self.assertEqual(
            data_layout.padding_ranges([(0x12F580, 5, 8), (0x12F588, 8, 8)]),
            [(0x12F585, 3, 0)],
        )

    def test_kprintf_fill_does_not_leak_to_the_next_gap(self):
        self.assertEqual(
            data_layout.padding_ranges([(0x152300, 0x6D4, 16), (0x1529E0, 0x64, 16), (0x152A48, 8, 8)]),
            [(0x1529D4, 12, 0xCD), (0x152A44, 4, 0)],
        )

    def test_unexplained_gap_fails(self):
        with self.assertRaisesRegex(ValueError, "would link at 0x12f588, expected 0x12f590"):
            data_layout.padding_ranges([(0x12F580, 5, 8), (0x12F590, 8, 8)])

    def test_compiled_inputs_cannot_overlap_across_output_sections(self):
        with self.assertRaisesRegex(ValueError, "sections overlap"):
            data_layout.padding_ranges([(0x12F580, 0x22D84, 8), (0x152300, 8, 8)])

    def test_linker_input_uses_explicit_table_alignment(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            with patch.object(data_layout, "compiled_data", return_value=[
                ("kprintf.o", ".rodata.jtbl_001529E0", 0x1529E0),
                ("lights.o", ".data.D_001E7E80", 0x1E7E80),
            ]), patch.object(data_layout.data_in_c, "interior", return_value={}):
                data_layout.linker_inputs(path)
            self.assertEqual((path / "core_rdata.ld").read_text().splitlines(), [
                "    FILL(0xCDCD);", "    . = ALIGN(16);", "    FILL(0);",
                "    kprintf.o(.rodata.jtbl_001529E0)",
            ])
            self.assertEqual((path / "data.ld").read_text().splitlines(), [
                "    . = ALIGN(16);", "    lights.o(.data.D_001E7E80)",
            ])
