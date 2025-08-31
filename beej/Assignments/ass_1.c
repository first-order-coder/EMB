#include <stdio.h>

int main() {
    int num;

    printf("Enter the number: ");
    scanf("%d",  &num);

    while (num > 0){ /* if the number inputted is higher than 0 then while loop will execute if its lower than or equal the condition is false and therefore while loop will exit*/
        printf("You entered: %d\n", num);

        printf("Enter the number: ");
        scanf("%d",  &num);
        
    }
    printf("You entered negative or zero: %d\n", num);
        
    return 0;
}