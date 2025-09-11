#include <stdio.h>
#include <stdint.h>

int main(){

    uint8_t count = 0b10000100;

    if (count & (1<<2)) {
    printf("Bit 2 is ON\n"); //we are cheking bit by bit using and operator.
    } else {
    printf("Bit 2 is OFF\n");
    }

   if ((count & ((1<<7)|(1<<0))) == ((1<<7)|(1<<0))){
    printf("Bit 7 and Bit 2 is ON\n");
   }else {
    printf("Bit 7 and/or Bit 2 is OFF\n");
   }

    return 0;


}