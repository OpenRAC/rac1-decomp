import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tidy"))
import gp_scalars as gp  # noqa: E402

TEXT = "extern short D_L00_00161CA0;\nfloat f(void) { return *(float *)&D_L00_00161CA0; }\n"


class GpScalarTest(unittest.TestCase):
    def test_one_cast_type_converts(self):
        self.assertEqual(gp.candidates(TEXT), {"D_L00_00161CA0": "float"})
        self.assertEqual(gp.apply(TEXT, {"D_L00_00161CA0": "float"}, {}),
                         "extern float D_L00_00161CA0 SDATA(D_L00_00161CA0);\nfloat f(void) { return D_L00_00161CA0; }\n")

    def test_a_readable_name_uses_its_address(self):
        text = "extern short speed;\nfloat f(void) { return *(float *)&speed; }\n"
        self.assertIn("extern float speed SDATA(D_L00_00161CA0);", gp.apply(text, {"speed": "float"}, {"speed": {"D_L00_00161CA0"}}))

    def test_two_cast_types_stay(self):
        text = TEXT + "int g(void) { return *(int *)&D_L00_00161CA0; }\n"
        self.assertEqual(gp.candidates(text), {})

    def test_a_plain_use_stays(self):
        self.assertEqual(gp.candidates(TEXT + "short h(void) { return D_L00_00161CA0; }\n"), {})

    def test_a_fragment_counts(self):
        self.assertEqual(gp.candidates(TEXT, "int v(void) { return *(int *)&D_L00_00161CA0; }\n"), {})
        self.assertEqual(gp.candidates(TEXT, "float v(void) { return *(float *)&D_L00_00161CA0; }\n"),
                         {"D_L00_00161CA0": "float"})

    def test_a_field_of_it_stays(self):
        self.assertEqual(gp.candidates("extern short x;\nfloat f(void) { return (*(float *)&x)[1]; }\n"), {"x": "float"})
        self.assertEqual(gp.candidates("extern short x;\nint a = *(int *)&x[1];\n"), {})

    def test_no_address_name_means_no_change(self):
        text = "extern short speed;\nfloat f(void) { return *(float *)&speed; }\n"
        self.assertEqual(gp.apply(text, {"speed": "float"}, {}), text)


if __name__ == "__main__":
    unittest.main()
