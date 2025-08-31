#include <stdio.h>

void print_plus_one(void){

    static int a = 0;
    printf("%d\n", a);

    a++;
}

int main(void){

    print_plus_one();
    print_plus_one();
    print_plus_one();
    print_plus_one();
    print_plus_one();

    return 0;
}