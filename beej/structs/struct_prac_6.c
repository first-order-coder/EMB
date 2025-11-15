#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct cl{
    bool is_letter;
    bool is_upper;
    char lower;
} CharInfo;

CharInfo checkCharacter (char ch){
    unsigned char u = ch;

    CharInfo info = {
        .is_letter = false,
        .is_upper = false,
        .lower = ch
    };

    if (isalpha(u)) {
        info.is_letter = true;
        info.is_upper = isupper(u) != 0;
        info.lower = (char)tolower(u);
    }

    return info;
};
 
int main() {
    char input = 'ñ';

    CharInfo character = checkCharacter(input);
    printf("The character entered:%c and Is a letter:%d , Uppercase:%d and in Lowercase:%c\n", input, character.is_letter, character.is_upper, character.lower); 

    return 0;
}