#include <stdio.h>

/*
struct a_struct_with_a_very_large_name {
    int age;
    int height;
};

typedef struct a_struct_with_a_very_large_name AGEHEIGHT;
*/
/* the same can be done with:*/

typedef struct{
    int age;
    int height;
} AGEHEIGHT; /* there is no need to say struct every where when used*/

void change_bio(AGEHEIGHT *person){
    person->age = 25;
    person->height = 188;
}


int main(){
    AGEHEIGHT jack;

    change_bio(&jack);

    printf("Age: %d and Height: %d", jack.age, jack.height);
}