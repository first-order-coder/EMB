#include <stdio.h>
#include <stdlib.h>

int main(){

    char line[100];

    printf("Enter a line: ");
    if (fgets(line, sizeof line, stdin)) {
        fprintf(stderr, "No input.\n");
        return EXIT_FAILURE;
    }

    const char *path = "text_files//write_to_file.txt";
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Failed to open file for writing");
        return EXIT_FAILURE;
    }
    
    if (fputs(line, fp) == EOF) { //EOF means end of line
        perror("Write error");
        fclose(fp);
        return EXIT_FAILURE;
    }
}