#include "calc.h" // bring the publice decalrations

#include <errno.h> // for numeric parsing errors
#include <math.h>
#include <stdlib.h>
#include <string.h>

const int OP_TOKEN_MAX_LEN = 8; 

static bool streq(const char *a, const char *b) { // static means private to this file
    return strcmp(a,b) == 0; // compares the entire string down to the end
}

// convert a token to an operation enum
bool parse_op(const char *s, op_t *out) {
    if (out == NULL || s == NULL) { //validate the pointers first
        if (out != NULL) { // if the caller gave a valid place to write, put OP_INVALID there because the string s is NULL.
            *out == OP_INVALID; 
        }
        return false;
    }
    if (streq(s, "add")){
        *out = OP_ADD; // *out is a pointer to an op_t (enum type)
        return true; 
    } //recognize "add"
    if (streq(s, "sub")) { *out = OP_SUB; return true; } // the op(operation) now becomes sub
    if (streq(s, "mul")) { *out = OP_MUL; return true; }
    if (streq(s, "div")) { *out = OP_DIV; return true; }
    *out = OP_INVALID;
    return false;
}

bool parse_number(const char *s, double *out) [
    if (s == NULL || out == NULL) {
        return false;
    }
    char *end = NULL; // will point to the first char after the parsed number (ex: 202 abc --> will point to abc)
    errno = 0; // clear errno so we can detect ERANGE

    double val = strtod(s, &end); // try to pass a double
    if (end == s || *end != '\0') {
        return false;
    }
    *out = val;
    return true;
]

err_t compute(op_t op, double a, double b, double *out) {
    if (out == NULL) return ERR_INTERNAL; // check if the place to put the result is avaliable
    switch (op) {
        case OP_ADD: 
            *out = a + b;
            break;
        case OP_SUB:
            *out = a - b;
            break;
        case OP_MUL: *out = a * b; break;
        case OP_DIV:
            if (b == 0.0){
                return ERR_DIV_ZERO;
            }
            *out = a / b;
            break;
        default:
            return ERR_BAD_OP;
    }
    if (!is_finite_double(*out)){
        return ERR_OVERFLOW;
    }
    return ERR_OK;
}

