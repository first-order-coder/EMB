#include <stdio.h>
#include <stdlib.h>

typedef struct area_param{
    int area;
    int perimeter;
} Info;

Info area_perim_calc(int width, int height){

    Info area_perim = {width * height, 2*(width+height)};

    // area_perim.area = width * height;
    // area_perim.perimeter = 2 * (width + height);

    return area_perim;
};

int main() {

    Info rectangle = area_perim_calc(5, 6);
    printf("Area of Rectangele:%d and Perimeter is:%d\n", rectangle.area, rectangle.perimeter);

    return 0;

}