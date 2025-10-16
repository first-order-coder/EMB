#include <stdio.h>
#include <string.h>

int main(){

    char dest[20] = "Hello"; //this is contained in an array since this needs to be edited later
    char *src = ", World!";
    char numbers[] = "12345678";

    printf("dest before strcat \"%s\" \n", dest);

    strcat(dest, src);
    printf("dest after strcat: \"%s\"\n", dest);
    
    strncat(dest, numbers, 3);
    printf("dest after strncat: \" %s \" \n",  dest);

    return 0;
}