#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct creature{
    float x;
    float y;
};

void execute_behavior(struct creature *c){

    int dx = (rand() % 3) - 1; /* rand should give values between 0, 1, 2 and then by -1 the values are shifted between -1, 0, 1*/
    int dy = (rand() % 3) - 1;

    c->x += dx * 0.5;
    c->y += dy * 0.5;
}

int main(void){

    srand(time(NULL)); /* to prevent the program from getting the same seed everytime we used srand to define a seed every second*/
    /* uses the current time as a seed to create new sequences every time*/

    int i;
    int loop;

    struct creature guys[10];

    for(i=0; i < 10; i++){

        guys[i].x = (float)i;
        guys[i].y = (float)i;
    }
   

    for(loop=0; loop < 10; loop++){

        for(i=0; i < 10; i++){
            execute_behavior(&(guys[i]));
        
        }

        printf("Loop Num: %d\n", loop+1);
        for(i=0; i < 10; i++) {
            printf("Creature Num: %d and cordinates:(%.2f, %.2f)\n", i, guys[i].x, guys[i].y);
        }
    }
        printf("\n");
}