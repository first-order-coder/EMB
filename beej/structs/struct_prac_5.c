#include <stdio.h>
#include <stdlib.h>

typedef struct int_compare{
    int bigger;
    int difference;
} Compare;

Compare compare_nums (int a, int b){
    Compare num1 = {0};
    if (a > b) {
        num1.bigger = a;
    } else {
        num1.bigger = b;
    }
    num1.difference = abs(a-b);
    return num1;
};

int main (){
    Compare num_analyze = compare_nums(5, 18);
    printf("The bigger number is:%d and the absolute diff is:%d\n", num_analyze.bigger, num_analyze.difference);
    return 0;
}