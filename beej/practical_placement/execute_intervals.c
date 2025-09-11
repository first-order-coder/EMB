#include <stdio.h>

int main(){

    int next_tick = 0;
    int i;
    int block;

    for(i = 0; i < 61; i++){
        block = i / 10; // seconds are separated in to 6 blocks, and each block consists of 10 seconds (0->9), (10->19)...
        //by changing the denominator value we can change the block sizes.
        next_tick = block % 6; // this cycles every 6 blocks (so every 60 seconds) --> which step of the cycle (0-5 am i on)
        
        printf("Seconds: %2d | block: %d | Next Tick: %d\n",i, block, next_tick);
    }
    
    return 0;
}