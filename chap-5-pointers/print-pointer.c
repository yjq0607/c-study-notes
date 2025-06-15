#include <stdio.h>


void change(int *cj)
{
    *cj = 20;
}

int main(void)
{
    int i = 10;
    int *p = &i;  // declarationa and assignment at the same time

    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", p);  // not particularly useful, just for illustration

    /* 
     * dereferencing the pointer and changing the value
     * this looks like mutating the variable value without assignment
     * */
    // *p = 20;  // dereferencing *p which points to the address of variable "i"
    change(p);
    printf("Now the value of i is %d\n", i);
    printf("If it is read from dereferencing the pointer it also is %d\n", *p);

    return 0;
}

