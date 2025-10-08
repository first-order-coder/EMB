#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;

    printf("Enter the values-> a and b:\n");
    if (scanf("%d %d", &a, &b) != 2){
        fprintf(stderr, "Input Error: please enter 2 integers.\n");
        return exit(EXIT_FAILURE); //terminate the program with exit faliure.
    }

    const char *path = "text_files\\input_values.txt";
    FILE *fp = fopen(path, "w");

    // error checking the file that was opened
    if (fp == NULL) {
        perror("Error the file cannot be open:");
        exit(1);
    } 
    
    else {
        fprintf(fp, "a = %d and b = %d\n", a, b);
        fprintf(fp, "a + b = %d\n", a+b);
        printf("Data was written succesfully");
    }

    fclose(fp);
    return 0;
}