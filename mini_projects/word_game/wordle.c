#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //unix standard header for low level operating system function on Linux

#define ResultGreen  1
#define ResultYellow 2
#define ResultRed    4

typedef struct s_result {
    char color[5];
} Result;

Result checkchar(char,char,int,char*);

Result checkchar(char correct, char guess, int idx, char *word) {

};

int main() {

}

