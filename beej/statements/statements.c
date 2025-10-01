#include <stdio.h>

int main() {
    int i = 10;
    int *p = &i;
    const char *y = "hello";

    /*if (i > 10) {
        printf("i is bigger than 10");
    }
    else if (i <= 10) {
        printf("i is not bigger than 10");
    }
    return 0; */

    while (i < 10){
        printf("i is now %d \n", i);
        i++;
    }   
    printf ("%d\n", p);
    printf ("%d\n", *p);
    printf("%s", y);
    
}
