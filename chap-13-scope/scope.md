# Scope in for loop

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++) {
        int i = 999;  // Hides the i in the for-loop scope
        printf("%d\n", i);
    }
}
```

> [!NOTE]
> A bit interesting property here\
> `i` is declared in both `for` loop statement as well as inside the `for` loop\
> the inner `i` "hides" the `i` in the for statement, but not overwriting it.\
> Therefore, the statement is `printf` 5 times

