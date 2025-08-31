#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n = 5;

    int *arr1 = malloc(n * sizeof(int));
    int *arr2 = calloc(n, sizeof(int));

    printf("malloc array: \n");
    for(int i = 0; i < n; i++){

        printf("%d", arr1[i]);

    }

    printf("\n calloc array: \n");
    for(int i = 0; i < n; i++){

        printf("%d", arr2[i]);

    }

    free(arr1);
    free(arr2);

    return 0;

}