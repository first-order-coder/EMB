#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() { 

    // FILE *fp = fopen("HW_6.txt", "r");
    // if (fp == NULL) {
    //     perror("Error opening file:");
    // } else {
    //     fclose(file);
    // }
    // return 0;

    // both options are valid:

    FILE *fp;
    if ((fp = fopen("text_files\\HW_6.txt", "r")) == NULL){
        perror("Error opening file:");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof line, fp)) {
        printf("Got: %s", line);
    }
    fclose(fp);
    return 0;

}