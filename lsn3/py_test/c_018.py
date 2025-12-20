import re
import test_utils

def count(inp_text):
    char_count = len(inp_text)
    word_count = len(re.findall(r"[^ \t\n]+", inp_text))
    line_count = inp_text.count('\n')

    return f"{char_count} {word_count} {line_count}\n"

if __name__ == "__main__":
    test_utils.run_py_prog(count)
