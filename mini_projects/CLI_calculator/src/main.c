#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

static void print_usage(const char *prog) {
    fprintf(stderr, "Usage: %s <op> <a> <b>\n", prog); // show how to call (also by redirecting to stderr the normal output stays clean the usage logs would be much clear).
    fprintf(stderr, " <op> = add | sub | mul | div\n");
    fprintf(stderr, " <a>, <b> = numbers (ints or floats)\n"); 
}

// argv is an argument vector --> an array of C-strings(pointers to char).
int main(int argc, char **argv) {
    if (argc != 4) { //expect exactly 3 args after program name --> 
                     //argv[1] -> first argument ("add")
                     //argv[2] -> second argument ("4")
                     //argv[3] -> third argument ("7")
        print_usage(argv[0]); //argv[0] is the program name --> ./calc
        return ERR_BAD_USAGE;
    }

    op_t op;
    if (!pars_op(argv[1], &op)){
        fprintf(stderr, "Unknown Operaton: %s\n", argv[1]);
        print_usage(argv[0]); //remind the user of valid ops
        return ERR_BAD_OP;
    }

    double a, b, result;
    if (!parse_number(argv[2], &a)) {
        fprintf(stderr, "Invalid Number: %s\n", argv[2]);
        return ERR_BAD_NUMBER;
    }
    if (!parse_number(argv[3], &b)) {
        fprintf(stderr, "Invalid Number: %s\n", argv[3]);
        return ERR_BAD_NUMBER;
    }

    err_t err = compute(op, a, b, &result);
    if (err != ERR_OK) {
        if (err == ERR_DIV_ZERO) fprintf(stderr, "Division by zero.\n");   // Specific message
        else if (err == ERR_OVERFLOW) fprintf(stderr, "Computation overflow/invalid result.\n");
        else if (err == ERR_BAD_OP)  fprintf(stderr, "Bad operation.\n");
        else fprintf(stderr, "Internal error.\n");                          // Fallback
        return err;
    }

    prinf("%.10g\n", result); //print result with upto 10 significant digits
    return ERR_OK; // indicate success to the shell
}