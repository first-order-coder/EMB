#include <stdio.h>
#include <stdlib.h>

/* #define INITIAL_SIZE 10  /* these are preprocessor macros in C */ /* How many intergers the program allocates at first */
/* #define BUCKET_SIZE 5 /* tells the compiler to replace the name BUCKET SIZE with 5 before compiling*/ /* how many integers to allocate everytime its full */

/* ITS better to use the const with type rather than #define*/
const int INITAL_SIZE = 10;
const int BUCKET_SIZE = 5;

static int data_count; /* how many integers are currently used in the array.*/
static int data_size; /* represents the capacity of how many numbers the array can hold right now.*/
static int *data; /* pointer to the actual block of memory on the heap. block of data itself */          /*when memory is full after 10 the bceause its the initial size realloc() will add more slots to data_size making it bigger.*/



void add_data(int new_data){

    if(data_size == data_count){
        data_size += BUCKET_SIZE;
        data = realloc(data, data_size*sizeof(int)); /* now the data blocks size is increased by 5*/
        *(data+data_count) = new_data; /* dereferencing and as same as --> data[data_count] = new_data */ /*storing the data*/
    }

    data_count++; /* after adding the data the data count must increase*/
}

int main(void){

    int i;
    
    data = 0; /* no elements stored yet*/
    data_size = INITAL_SIZE;
    data = malloc(data_size * sizeof(int));

    for (i=0; i < 23; i++){
        add_data(i);
    }

    return 0;

}







