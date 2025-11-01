#ifndef CALC_H // if CALC_H is not yet defined
#define CALC_H // then define it (this is a header guard to prevent double inclusion)

#include <stdbool.h>

// the operations calculator will support
typedef enum {  // creates named integer constants
    OP_ADD, // by default firsnt name is assigned 0 and then next one 1, after 2, etc
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_INVALID
} op_t; // type name for this enum instead of using enum name_of_enum evertime typedef is better

// error exit codes
typedef enum {
    ERR_OK = 0,
    ERR_BAD_USAGE = 64,
    ERR_BAD_NUMBER = 65,
    ERR_BAD_OP = 66,
    ERR_DIV_ZERO = 67,
    ERR_OVERFLOW = 68,
    ERR_INTERNAL = 70
} err_t; 

// to access the op_token_max_len across multiple files 
extern const int OP_TOKEN_MAX_LEN; // extern says: the storage lives elsewhere

// pass a word like "add" into an op_t, returns true on success.
bool parse_op(const char *s, op_t *out);  // if the typed word is correct then returns true

// parse a string into a double strictly (rejects junk)
bool parse_number(const char *s, double *out); // write the result to *out.

// performs the operation 'op' on a and b and then writes the resulst to *out
// returns ERR_OK on success, otherwise an appropriate error code.
err_t compute(op_t op, double a, double b, double *out);

#endif // end of header guard