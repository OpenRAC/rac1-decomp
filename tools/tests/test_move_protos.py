import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tidy"))
import move_protos as mp  # noqa: E402

HOME = "void f(int a) { }\nvoid g(void) { }\n"
USER = '#include "common.h"\nextern void f(int a);\nvoid u(void) { f(1); }\n'


class PlanTest(unittest.TestCase):
    def plan(self, sources, fragments=None, aliases=None):
        return mp.plan(sources, fragments or {}, aliases or {})

    def test_same_text_in_two_files_moves_to_the_defining_files_header(self):
        headers, takes = self.plan({"src/game/d.c": HOME, "src/game/a.c": USER, "src/game/b.c": USER})
        self.assertEqual(headers, {"game/d.h": {"f": "extern void f(int a);"}})
        self.assertEqual(takes["src/game/a.c"], {"game/d.h": {"f"}})

    def test_one_user_is_not_enough(self):
        headers, _ = self.plan({"src/game/d.c": HOME, "src/game/a.c": USER})
        self.assertEqual(headers, {})

    def test_different_text_stays(self):
        other = "extern int f(int a);\n"
        headers, _ = self.plan({"src/game/d.c": HOME, "src/game/a.c": USER, "src/game/b.c": USER, "src/game/c.c": other})
        self.assertEqual(headers, {})

    def test_qualifiers_and_types_stay(self):
        self.assertFalse(mp.is_candidate("f", 'extern void f(void) __asm__("func_1");'))
        self.assertFalse(mp.is_candidate("f", "extern void f(struct Moby *m);"))
        self.assertFalse(mp.is_candidate("f", "extern void f(Vec4 *v);"))
        self.assertFalse(mp.is_candidate("x", "extern int x;"))
        self.assertTrue(mp.is_candidate("f", "extern s32 f(void *a, float b);"))

    def test_two_definitions_stay(self):
        headers, _ = self.plan({"src/game/d.c": HOME, "src/game/e.c": HOME, "src/game/a.c": USER, "src/game/b.c": USER})
        self.assertEqual(headers, {})

    def test_a_file_using_another_name_of_the_header_keeps_its_declarations(self):
        both = "extern void g(void);\n"
        clash = "extern void f(int a);\nvoid u(void) { g(); }\n"
        sources = {"src/game/d.c": HOME, "src/game/a.c": USER, "src/game/b.c": USER, "src/game/c.c": clash,
                   "src/game/x.c": both, "src/game/y.c": both}
        _, takes = self.plan(sources)
        self.assertNotIn("src/game/c.c", takes)

    def test_a_version_fragment_counts_as_using_a_name(self):
        sources = {"src/game/d.c": HOME, "src/game/a.c": USER, "src/game/b.c": USER, "src/game/c.c": USER,
                   "src/game/x.c": "extern void g(void);\n", "src/game/y.c": "extern void g(void);\n"}
        _, takes = self.plan(sources, fragments={"src/game/c.c": "void v(void) { g(); }\n"})
        self.assertNotIn("src/game/c.c", takes)
        self.assertIn("src/game/a.c", takes)


class ApplyTest(unittest.TestCase):
    def test_declaration_goes_and_include_comes_after_the_last_include(self):
        new = mp.apply_to_source(USER, {"game/d.h": {"f"}})
        self.assertEqual(new, '#include "common.h"\n#include "game/d.h"\n\nvoid u(void) { f(1); }\n')

    def test_a_provenance_note_keeps_the_declaration(self):
        text = '#include "common.h"\nextern void f(int a); /* Adapted from Lombyte\'s project */\n'
        self.assertIn("Adapted", mp.apply_to_source(text, {"game/d.h": {"f"}}))

    def test_header_text(self):
        text = mp.header_text("game/d.h", {"f": "extern void f(int a);"})
        self.assertIn("#ifndef GAME_D_H", text)
        self.assertIn("src/game/d.c", text)
        self.assertIn("extern void f(int a);\n", text)


if __name__ == "__main__":
    unittest.main()
