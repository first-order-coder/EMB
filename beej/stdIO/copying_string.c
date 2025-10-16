#include <stdio.h>
#include <string.h>

int main(){

    char *src = "hockey hockey hockey hockey hockey hockey hockey"; 
    char dest[20]; // 20 byts total 19 visible + 1 null terminator

    int len;

    strcpy(dest, "I like ");
    printf("dest: %s\n", dest);

    len = strlen(dest); // now the length is 7
    // already in dest first 7 bytes are filled with "I like " part

    strncpy(dest+len, src, sizeof(dest) - len - 1); //dest+len points to first free byte after "I like " index 7
    // sizeof(dest) - len - 1 = 20 - 7 - 1 = 12 --> the -1 is for final terminator 

    dest[sizeof(dest)-1] = '\0'; // critical to add a terminator at end force it.

    printf("dest: %s", dest);
}