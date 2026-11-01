import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import data_in_c as d  # noqa: E402

WORDS = """
/* 0 165580 00000001 */ .word 0x00000001
/* 4 165584 00000002 */ .word 0x00000002
"""
POINTER = "/* 0 165580 00000001 */ .word func_00112380\n"
MIXED = "/* 0 165580 00000001 */ .word 0x1\n/* 4 165584 00 */ .byte 0x1\n"


class ValuesTest(unittest.TestCase):
    def test_plain_words(self):
        self.assertEqual(d.parse(WORDS), ("u32", ["0x00000001", "0x00000002"]))

    def test_a_pointer_or_a_mix_is_not_plain(self):
        self.assertIsNone(d.parse(POINTER))
        self.assertIsNone(d.parse(MIXED))

    def test_a_float_keeps_its_exact_bits(self):
        self.assertEqual(d.parse("/* 0 00165580 3F800000 */ .float 1\n"), ("u32", ["0x3F800000"]))

    def test_shorts_bytes_and_a_string(self):
        self.assertEqual(d.parse("/* 0 00165580 */ .short 0x0003\n"), ("u16", ["0x0003"]))
        self.assertEqual(d.parse("/* 0 00165580 */ .byte 0x01\n"), ("u8", ["0x01"]))
        self.assertEqual(d.parse('/* 0 00165580 */ .asciz "Su"\n.align 2\n'), ("char", ['"Su"']))

    def test_two_strings_are_not_one_block(self):
        self.assertIsNone(d.parse('.asciz "a"\n.asciz "b"\n'))

    def test_render(self):
        self.assertEqual(d.render(["0x1"]), "0x1\n")
        self.assertEqual(d.render(["0x1", "0x2"]), "0x1, 0x2,\n")


class FitsRetailTest(unittest.TestCase):
    def test_gcc_aligns_aggregates_to_8(self):
        self.assertTrue(d.fits_retail("D_00165580", 4))
        self.assertTrue(d.fits_retail("D_00165584", 1))
        self.assertFalse(d.fits_retail("D_00165584", 2))
        self.assertFalse(d.fits_retail("D_00165584", 1, "char"))
        self.assertTrue(d.fits_retail("D_00165580", 1, "char"))


class SourceTest(unittest.TestCase):
    def write(self, entries, names=None):
        with tempfile.TemporaryDirectory() as folder, patch.object(d, "ROOT", Path(folder)):
            d.write_source("src/data/game/x.c", entries, names or {})
            return (Path(folder) / "src/data/game/x.c").read_text()

    def test_no_values_in_the_source(self):
        text = self.write([("D_00165580", "u32", 2), ("D_00165590", "u32", 1)])
        self.assertIn('u32 D_00165580[] DATA_SECTION(D_00165580) = {\n#include "data_inc/D_00165580.inc"\n};', text)
        self.assertIn("u32 D_00165590 DATA_SECTION(D_00165590) =", text)
        self.assertNotIn("0x", text)

    def test_a_readable_name_is_used_and_the_section_keeps_the_address(self):
        text = self.write([("D_00165580", "u32", 2)], {"D_00165580": "fog_table"})
        self.assertIn("u32 fog_table[] DATA_SECTION(D_00165580) = {", text)

    def test_a_string(self):
        text = self.write([("D_00165580", "char", 1)])
        self.assertIn('char D_00165580[] DATA_SECTION(D_00165580) =\n#include "data_inc/D_00165580.inc"\n;', text)

    def test_segments(self):
        self.assertEqual(d.segment_of("D_0012F580"), "core")
        self.assertEqual(d.segment_of("D_00165580"), "data")


if __name__ == "__main__":
    unittest.main()
