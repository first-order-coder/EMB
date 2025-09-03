#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    
    char *end;

    long a = strtol(argv[1], &end, 10);
    printf("%ld", a);

    long b = strtol(argv[2], &end, 10);
    printf("%ld", b);

    printf("a+b=%d\n", a + b);

}