# Array

Pointer to array is just pointer to the first element


```c
#include <stdio.h>

void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++) {  // beej's demo func is explicitly defined the dimension of the array to be taken into, how should a dynamic func look like?
        for (int col = 0; col < 3; col++) {
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x);
}
```

> [!CAUTION]
> Remember that the compiler does minimal compile-time bounds checking (if you’re lucky),\
> and C does zero runtime checking of bounds.\
> No seat belts! Don’t crash by accessing array elements out of bounds!
