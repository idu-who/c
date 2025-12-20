/*
Differential testing using python.
BASE_DIR         : Base directory containting programs and input files
C_FILE           : C program to be tested
PY_FILE          : Python program to use for testing
TOTAL_TEST_FILES : Total number of input files
BUFFER_SIZE      : Size of character arrays (command, file_name, py_out, c_out)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_DIR "/home/idu/Projects/C/lsn3/py_test/"
#define PY_FILE "c_018.py"
#define C_FILE "c_018.o"
#define TOTAL_TEST_FILES 1
#define BUFFER_SIZE 200

bool run_test(const char f_no[]);
void run_py_prog(const char f_no[]);
void run_c_prog(const char f_no[]);
FILE *open_out_file(const char f_no[], const char suffix[]);
long int file_size(FILE *file);

int main() {
    char f_no[3]; // file_number string

    for (unsigned int i = 1; i <= TOTAL_TEST_FILES; i++) {
        printf("Test %d : ", i);

        sprintf(f_no, "%d", i); // int to string

        if (run_test(f_no))
            printf("PASS\n");
        else
            printf("FAIL\n");
    }

    return 0;
}

// run test for input<f_no>.txt
bool run_test(const char f_no[]) {
    run_py_prog(f_no);
    run_c_prog(f_no);

    FILE *py_out_file = open_out_file(f_no, "-py");
    FILE *c_out_file = open_out_file(f_no, "-c");

    if (py_out_file != NULL && c_out_file != NULL) {
        char py_out[BUFFER_SIZE], c_out[BUFFER_SIZE];

        // compare output size
        if (file_size(py_out_file) != file_size(c_out_file)) {
            printf("\nOutput file size mismatch.\n");
            fclose(py_out_file);
            fclose(c_out_file);
            return false;
        }

        // compare output data
        while ((fgets(py_out, sizeof(py_out), py_out_file) != NULL) &&
               (fgets(c_out, sizeof(c_out), c_out_file)) != NULL) {

            if (strcmp(py_out, c_out) != 0) {
                printf("\nOutput data mismatch.\n");
                fclose(py_out_file);
                fclose(c_out_file);
                return false;
            }
        }
    } else {
        fprintf(stderr, "\nCould not open output file.\n");

        if (py_out_file != NULL)
            fclose(py_out_file);
        else if (c_out_file != NULL)
            fclose(c_out_file);
        return false;
    }

    return true;
}

/* run python program on input<f_no>.txt, produces output<f_no>-py.txt */
void run_py_prog(const char f_no[]) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "python3 %s%s %s", BASE_DIR, PY_FILE,
             f_no);

    // python3 /home/idu/Projects/C/lsn3/py_test/c_018.py 1
    if (system(command) != EXIT_SUCCESS)
        fprintf(stderr, "\nPython program exited with an error.\n");
}

// run C program on input<f_no>.txt, produces output<f_no>-c.txt
void run_c_prog(const char f_no[]) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "%s%s < input%s.txt > output%s-c.txt",
             BASE_DIR, C_FILE, f_no, f_no);

    // /home/idu/Projects/C/lsn3/py_test/c_018.o < input1.txt > output1-c.txt
    if (system(command) != EXIT_SUCCESS)
        fprintf(stderr, "\nC program exited with an error.\n");
}

FILE *open_out_file(const char f_no[], const char suffix[]) {
    char file_name[BUFFER_SIZE];
    snprintf(file_name, sizeof(file_name), "%soutput%s%s.txt", BASE_DIR, f_no,
             suffix);

    // /home/idu/Projects/C/lsn3/py_test/output1-py.txt
    // /home/idu/Projects/C/lsn3/py_test/output1-c.txt
    return fopen(file_name, "r");
}

long int file_size(FILE *fp) {
    long int size;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    return size;
}
