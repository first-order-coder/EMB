#include <stdio.h>

int plus_one(int n){

    return n + 1;

}

int main(void){
    
    int i = 10, j, k;
    
    j = plus_one(plus_one(i));
    printf("Value of j is: %d\n", j);
    
    k = plus_one(i);
    printf("Value of k is: %d", k);

    return 0;

}