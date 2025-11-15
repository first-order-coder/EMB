#include <stdio.h>
#include <stdlib.h>

typedef struct num_attr{
    int is_even;
    int is_odd;
    int is_positive;  
    int is_negative;
    int is_zero;
} Numberinfo;

Numberinfo analyze_number(int num){
    Numberinfo info = {0}; //initalize everything to zero

    if (n == 0) {
        info.is_zero = 1;
        info.is_even = 1;
        return info;
    }

    info.is_even = (num % 2 == 0);
    info.is_odd = (num % 2  != 0);

    return info;
};

int main(){

    Numberinfo new_number = check_number(5);
    printf("The number u entered is:%d and is Positive:%d, is Even:%d\n", 5, new_number.is_positive, new_number.is_even);

}