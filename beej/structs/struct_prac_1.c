#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct std_data{
    char std_name[20];
    int std_age;
} Student_data;

Student_data std_info(char *name, int age){
    Student_data s1;

    strcpy(s1.std_name, name);
    s1.std_age = age;

    return s1;
};


int main() {

    Student_data first = std_info("John", 38);
    printf("Name:%s and Age:%d\n", first.std_name, first.std_age);

    return 0;
}