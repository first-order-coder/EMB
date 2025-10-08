#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char s[100];

    const char *path = "text_files\\write_to_file.txt"; 
    FILE *fp = fopen(path, "r");

    if (fp == NULL){
        perror("Error opening the file: It cannot be open");
        return EXIT_FAILURE;
    }

    if (fgets(s, sizeof(s), fp) == NULL){
        if (feof(fp)) { // feof means it will return f if you hit end-of-file.
            fprintf(stderr, "File is empty.\n");
        } else {
            perror("Read Error");
        }
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);
    printf("%s", s);
    return EXIT_SUCCESS;

}