#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct num_attr{
    int is_even;
    int is_odd;
    int is_positive;  
    int is_negative;
    int is_zero;
} Numberinfo;

Numberinfo analyze_number(int num){
    Numberinfo info = {0}; //initalize everything to zero

    if (num == 0) {
        info.is_zero = 1;
        info.is_even = 1;
        return info; // returning early makes the logic clearner and avoids extra work.
    }

    info.is_even = (num % 2 == 0);
    info.is_odd = (num % 2  != 0);
    info.is_positive = (num > 0);
    info.is_negative = (num < 0);

    return info;
};

void test_analyze_number(){

    //for positive odd cases
    Numberinfo a = analyze_number(5);
    assert(a.is_even == 0);
    assert(a.is_odd == 1);
    assert(a.is_positive == 1);
    assert(a.is_negative == 0);
    assert(a.is_zero == 0);

    //for negative odd cases
    Numberinfo b = analyze_number(-71);
    assert(b.is_even == 0);
    assert(b.is_odd == 1);
    assert(b.is_positive == 0);
    assert(b.is_negative == 1);
    assert(b.is_zero == 0);

    //for psotive even cases
    Numberinfo c = analyze_number(132.1);
    assert(c.is_even == 1);
    assert(c.is_odd == 0);
    assert(c.is_positive == 1);
    assert(c.is_negative == 0);
    assert(c.is_zero == 0);

    //for negative even cases
    Numberinfo d = analyze_number(-16);
    assert(d.is_even == 1);
    assert(d.is_odd == 0);
    assert(d.is_positive == 0);
    assert(d.is_negative == 1);
    assert(d.is_zero == 0);

    printf("all tests passed\n");

};

int main(){

    int input = 5;
    Numberinfo new_num = analyze_number(input);
    
    printf("Number: %d\n", input);
    printf(" Even:   %d\n", new_num.is_even);
    printf(" Odd:   %d\n", new_num.is_odd);
    printf(" Negative:   %d\n", new_num.is_negative);
    printf(" Positive:   %d\n", new_num.is_positive);

    test_analyze_number();
    return 0;

}