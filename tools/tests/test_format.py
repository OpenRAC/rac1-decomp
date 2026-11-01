import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import format as fmt  # noqa: E402


class FormatCheckTest(unittest.TestCase):
    def test_squeeze_ignores_whitespace_outside_strings_only(self):
        self.assertEqual(fmt.squeeze("int  a ;\n"), fmt.squeeze("int a;"))
        self.assertNotEqual(fmt.squeeze('char *s = "a b";'), fmt.squeeze('char *s = "ab";'))

    def test_line_continuations_may_move(self):
        self.assertEqual(fmt.squeeze("#define A \\\n  1\n"), fmt.squeeze("#define A 1\n"))

    def test_markers_must_start_the_line(self):
        self.assertEqual(fmt.tool_problems('\nINCLUDE_ASM("x", y);\n'), [])
        self.assertEqual(len(fmt.tool_problems('    ASM_FUNC("x", y);\n')), 1)

    def test_return_type_stays_with_the_name(self):
        self.assertEqual(fmt.tool_problems("void f(int a,\n       int b) {\n"), [])
        self.assertEqual(len(fmt.tool_problems("void\nf(int a) {\n")), 1)


if __name__ == "__main__":
    unittest.main()
