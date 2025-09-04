#include <stdio.h>

void *pointer_array[10];
int ptr_index = 0;

void append_pointer(void *p){
    pointer_array[ptr_index++] = p;
}

void *get_pointer(int i){
    return pointer_array[i];
}

int main(){

    char *s = "void pointers";
    int a = 23;
    int *b = &a;

    append_pointer(s);
    append_pointer(b);

    //before using get pointer we must state what type of values in the pointer_array are we trying to return 

    char *s2;
    int *b2;

    s2 = get_pointer(0);
    b2 = get_pointer(1);

    printf("%s\n", s2);
    printf("%d", *b2);
}


