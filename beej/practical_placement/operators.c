#include <stdio.h>

// creating a timer that will print Hurrah every 1000 ms this is based for ardunio board.

uint32_t last = 0;

void loop(){
    uint32_t now = millis(); //millis() tells how many seconds have passed since the board was turned on.
    if (now - last >= 1000){
        last = now;
        printf("Hurrah %d", last)
    }
}

int main(){
    loop()
}