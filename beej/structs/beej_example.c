#include <stdio.h>

struct mutantfrog {
    int num_legs;
    int num_eyes;
};

void build_beejs_frog(struct mutantfrog *f) { // in order to pass a parameter to a function it must be given a type (struct mutantfrog is the type of pointer (*f))
    
    f->num_legs = 10;
    f->num_eyes = 1;
}

int main(void) 
{
    struct mutantfrog rudolph;

    build_beejs_frog(&rudolph);

    printf("leg count: %d\n", rudolph.num_legs);
    printf("eye count: %d\n", rudolph.num_eyes);

    return 0;
}
