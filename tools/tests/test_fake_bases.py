import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tidy"))
import fake_bases as fb  # noqa: E402

BASES = {"hero_globals_base": 0x1000, "D_00001000": 0x1000}
TARGETS = {0x1E1D: "g_hero", 0x1100: "hero_control_mode"}


def new(text):
    return fb.rewrite(text, BASES, TARGETS)


class RewriteTest(unittest.TestCase):
    def test_a_field_through_the_hero(self):
        text = "void f(void) {\n    ((struct Hero *)(hero_globals_base + 0xE1D))->x = 1;\n}\n"
        self.assertIn("g_hero.x = 1;", new(text)[0])
        self.assertIn("extern Hero g_hero;", new(text)[0])

    def test_a_hero_pointer(self):
        self.assertIn("Hero *p = &g_hero;", new("void f(void) {\n    Hero *p = (Hero *)(hero_globals_base + 0xE1D);\n}\n")[0])

    def test_an_int_view_of_a_global(self):
        out = new("void f(void) {\n    int a = *(int *)(hero_globals_base + 0x100);\n}\n")[0]
        self.assertIn("int a = *(int *)hero_control_mode;", out)
        self.assertIn("extern char hero_control_mode[];", out)

    def test_a_scaled_constant_stays(self):
        text = "void f(void) {\n    int a = hero_globals_base + 0x100 * i;\n}\n"
        self.assertEqual(new(text), (text, 0))

    def test_no_global_there_stays(self):
        text = "void f(void) {\n    int a = *(int *)(hero_globals_base + 0x104);\n}\n"
        self.assertEqual(new(text), (text, 0))

    def test_a_comment_stays(self):
        text = "/* hero_globals_base + 0xE1D */\nint x;\n"
        self.assertEqual(new(text), (text, 0))

    def test_a_kept_function_stays(self):
        text = "void f(void) {\n    int a = *(int *)(hero_globals_base + 0x100);\n}\n"
        self.assertEqual(fb.rewrite(text, BASES, TARGETS, {"f"}), (text, 0))

    def test_a_blocked_global_stays(self):
        text = "void f(void) {\n    int a = *(int *)(hero_globals_base + 0x100);\n}\n"
        self.assertEqual(fb.rewrite(text, BASES, TARGETS, (), {"D_00001100"}), (text, 0))

    def test_declarations_that_disagree_block_it(self):
        text = ("extern int hero_control_mode;\nextern short hero_control_mode;\n"
                "void f(void) {\n    int a = *(int *)(hero_globals_base + 0x100);\n}\n")
        self.assertEqual(new(text)[1], 0)

    def test_an_address_alias_blocks_it(self):
        text = ('extern int hero_control_mode __asm__("D_1");\n'
                "void f(void) {\n    int a = *(int *)(hero_globals_base + 0x100);\n}\n")
        self.assertEqual(new(text)[1], 0)


if __name__ == "__main__":
    unittest.main()
