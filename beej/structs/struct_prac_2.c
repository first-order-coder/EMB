#include <stdio.h>
#include <stdlib.h>

typedef struct point_loc{
    int x;
    int y;
} Locations;

// the professional version of this 

Locations point_add (Locations p1, Locations p2){
    Locations result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    return result;
}; 

int main() {

    Locations A = {2,3};
    Locations B = {4,5};

    Locations C = point_add(A, B);
    
    printf("Location of Sector 1 is: X:%d and Y:%d or (%d,%d)\n", C.x, C.y,C.x, C.y);
    return 0;

}

// Locations point_arithmetic(int x1, int x2, int y1, int y2){
//     Locations L1;

//     L1.x = x1 + x2;
//     L1.y = y1 + y2;

//     return L1;
// };

// int main(){

//     Locations sector_1 = point_arithmetic(2,3,4,5);
//     printf("Location of Sector 1 is: X:%d and Y:%d or (%d,%d)\n", sector_1.x, sector_1.y,sector_1.x, sector_1.y);

//     return 0;
// }