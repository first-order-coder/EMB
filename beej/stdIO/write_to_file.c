#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    FILE *fp;

    if ((fp = fopen("text_files\\write_to_file.txt", "w")) == NULL) {
        perror("File not found:");
        exit(1);
    } else {
        fprintf(fp, "User %s logged in\n", "Isildur");
        printf("Data written to file successsfully.\n");
    }

    fclose(fp);
    return 0;
}