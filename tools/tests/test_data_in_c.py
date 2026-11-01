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
        self.assertEqual(d.values(WORDS, "u32"), ["0x00000001", "0x00000002"])

    def test_a_pointer_or_a_mix_is_not_plain(self):
        self.assertIsNone(d.values(POINTER, "u32"))
        self.assertIsNone(d.values(MIXED, "u32"))

    def test_render(self):
        self.assertEqual(d.render(["0x1"]), "0x1\n")
        self.assertEqual(d.render(["0x1", "0x2"]), "0x1, 0x2,\n")


class FitsRetailTest(unittest.TestCase):
    def test_gcc_aligns_aggregates_to_8(self):
        self.assertTrue(d.fits_retail("D_00165580", 4))
        self.assertTrue(d.fits_retail("D_00165584", 1))
        self.assertFalse(d.fits_retail("D_00165584", 2))


class SourceTest(unittest.TestCase):
    def test_no_values_in_the_source(self):
        blocks = {"D_00165580": WORDS, "D_00165590": "/* 0 0 0 */ .word 0xDEADBEEF\n"}
        with tempfile.TemporaryDirectory() as folder, patch.object(d, "ROOT", Path(folder)):
            d.write_source("src/data/game/x.c", ["D_00165580", "D_00165590"], blocks, {})
            text = (Path(folder) / "src/data/game/x.c").read_text()
        self.assertIn('u32 D_00165580[] DATA_SECTION(D_00165580) = {\n#include "data_inc/D_00165580.inc"\n};', text)
        self.assertIn("u32 D_00165590 DATA_SECTION(D_00165590) =", text)
        self.assertNotIn("0x", text)
        self.assertNotIn("DEADBEEF", text)

    def test_a_readable_name_is_used_and_the_section_keeps_the_address(self):
        with tempfile.TemporaryDirectory() as folder, patch.object(d, "ROOT", Path(folder)):
            d.write_source("src/data/game/x.c", ["D_00165580"], {"D_00165580": WORDS}, {"D_00165580": "fog_table"})
            text = (Path(folder) / "src/data/game/x.c").read_text()
        self.assertIn("u32 fog_table[] DATA_SECTION(D_00165580) = {", text)


if __name__ == "__main__":
    unittest.main()
