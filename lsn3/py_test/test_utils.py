import sys

def run_py_prog(logic_func):
    """
    Wrap progam logic with CLI and file handling for testing.
    """

    if len(sys.argv) < 2:
        print("Usage: python script.py <file_number>")
        sys.exit(1)

    f_no = sys.argv[1]
    inp_file_name = f"input{f_no}.txt"
    out_file_name = f"output{f_no}-py.txt"

    try:
        with open(inp_file_name) as inp_file:
            inp_text = inp_file.read()

        # logic_func should return string to be written into output_file
        result = logic_func(inp_text)

        with open(out_file_name, "w") as out_file:
            out_file.write(result)
    except FileNotFoundError:
        print(f"Error: {inp_file_name} not found.")
        sys.exit(1)
