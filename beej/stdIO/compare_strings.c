#include <stdio.h>
#include <string.h>

int main(){

    char *s1 = "Muffin";
    char *s2 = "Muffin Sandwich";
    char *s3 = "Muffin";

    if (!strcmp(s1, s3)){ // strcmp(s1, s3) returns 0 and by putting ! means if not(zero) == 1 (which is true)
        printf("They are the same");
    } else {
        printf("they are different");
    }

}