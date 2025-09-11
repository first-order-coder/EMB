#include <stdio.h>
#include <stdint.h>

int main(){

    uint8_t x = 252;
    uint8_t y = 53;

    uint8_t sum = x + y;
    uint8_t difference = y - x;
    printf("The sum is:%d and the difference is:%d", sum, difference); 
}