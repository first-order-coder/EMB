#include <stdio.h>

int main(){

    char *source = "Copy Me"; /* points to the first character of the char which is (C) */
    char *dest[20];

    char *sp;
    char *dp;

    for(sp = source, dp = dest; *sp != '0'; sp++, dp++){
        *dp = *sp; /*dereferencing the values for dp from sp*/
    }

    printf("%s\n", dest);

}