import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tidy"))
import switch_tidy as st  # noqa: E402


def wrap(cases):
    return "void f(int a) {\n    switch (a) {\n" + cases + "    }\n}\n"


class FallThroughTest(unittest.TestCase):
    def marked(self, cases):
        return st.rewrite(wrap(cases))[1]

    def test_a_plain_statement_runs_on(self):
        new = st.rewrite(wrap("        case 1:\n            g();\n        case 2:\n            break;\n"))
        self.assertEqual(new[1], 1)
        self.assertIn("            /* fall through */\n        case 2:", new[0])

    def test_break_return_goto_do_not(self):
        for leave in ("break;", "return;", "goto out;", "continue;"):
            self.assertEqual(self.marked(f"        case 1:\n            {leave}\n        case 2:\n            g();\n"), 0, leave)

    def test_an_if_without_else_runs_on(self):
        cases = "        case 1:\n            if (a) {\n                break;\n            }\n        case 2:\n            g();\n"
        self.assertEqual(self.marked(cases), 1)

    def test_a_block_that_breaks_does_not(self):
        self.assertEqual(self.marked("        case 1: {\n            g();\n            break;\n        }\n        case 2:\n            g();\n"), 0)

    def test_an_empty_case_is_a_shared_label(self):
        self.assertEqual(self.marked("        case 1:\n        case 2:\n            g();\n"), 0)

    def test_an_endless_loop_is_not_marked(self):
        self.assertEqual(self.marked("        case 1:\n            while (1) {\n                g();\n            }\n        case 2:\n            g();\n"), 0)

    def test_an_existing_note_is_kept(self):
        self.assertEqual(self.marked("        case 1:\n            g();\n            /* falls through to 2 */\n        case 2:\n            g();\n"), 0)

    def test_a_nested_switch_counts_separately(self):
        cases = ("        case 1:\n            switch (b) {\n                case 7:\n                    g();\n"
                 "                case 8:\n                    break;\n            }\n            break;\n        case 2:\n            g();\n")
        self.assertEqual(self.marked(cases), 1)


class EmptyTest(unittest.TestCase):
    def gone(self, cases):
        return st.remove_empties(wrap(cases))

    MIDDLE = "        case 1:\n            g();\n            break;\n        case 2:\n            break;\n        case 3:\n            g();\n            break;\n"

    def test_a_middle_case_goes(self):
        self.assertNotIn("case 2:", self.gone(self.MIDDLE))
        self.assertIn("case 3:", self.gone(self.MIDDLE))

    def test_an_edge_stays(self):
        cases = "        case 1:\n            break;\n        case 2:\n            g();\n            break;\n        case 3:\n            break;\n"
        out = self.gone(cases)
        self.assertIn("case 1:", out)
        self.assertIn("case 3:", out)

    def test_a_default_with_code_keeps_the_case(self):
        self.assertIn("case 2:", self.gone(self.MIDDLE + "        default:\n            h();\n"))

    def test_an_empty_default_goes(self):
        self.assertNotIn("default:", self.gone(self.MIDDLE + "        default:\n            break;\n"))

    def test_a_case_that_runs_into_it_keeps_it(self):
        cases = "        case 1:\n            g();\n        case 2:\n            break;\n        case 3:\n            g();\n            break;\n"
        self.assertIn("case 2:", self.gone(cases))

    def test_a_run_of_labels_goes_together(self):
        cases = ("        case 1:\n            g();\n            break;\n        case 2:\n        case 3:\n            break;\n"
                 "        case 4:\n            g();\n            break;\n")
        out = self.gone(cases)
        self.assertNotIn("case 2:", out)
        self.assertNotIn("case 3:", out)

    def test_a_comment_keeps_it(self):
        cases = "        case 1:\n            g();\n            break;\n        case 2: /* off */\n            break;\n        case 3:\n            g();\n            break;\n"
        self.assertIn("case 2:", self.gone(cases))

    def test_a_named_case_stays(self):
        cases = "        case 1:\n            g();\n            break;\n        case FOO:\n            break;\n        case 3:\n            g();\n            break;\n"
        self.assertIn("case FOO:", self.gone(cases))


class BaseTest(unittest.TestCase):
    def test_the_common_base_wins(self):
        out = st.rewrite(wrap("        case 0x10:\n        case 0x20:\n        case 5:\n            break;\n"))
        self.assertIn("case 0x5:", out[0])
        self.assertEqual(out[2], 1)

    def test_one_base_is_left_alone(self):
        text = wrap("        case 1:\n        case 2:\n            break;\n")
        self.assertEqual(st.rewrite(text)[0], text)

    def test_names_are_left_alone(self):
        self.assertIn("case FOO:", st.rewrite(wrap("        case FOO:\n        case 0x10:\n        case 5:\n            break;\n"))[0])


if __name__ == "__main__":
    unittest.main()
