# cmd environment

## Programme arguments
In `cmd`
> main.exe 1 2 3

The arguments can be accessed this way
```c
// main.c
#include <stdio.h>

int main(int argc, char *argv[])
{
        for (int i = 0; i < argc; i++) {
                    printf("arg %d: %s\n", i, argv[i]);
                        }
}

```

`argc`: number of arguments including the calling program
`argv`: array of strings separated by space

### argv
Here's a breakdown on `char *argv[]`\
Consider `argv[]` as an array, what type of items are stored inside the array?\
`char *` is the  type information which `argv[]` is holding.

Beej also demonstrated there is this style of declaring `argv`
```c
int main(int argc, char **argv)

```

Since an array `argv` is equivalent to a pointer, it can be replaced with pointer notation instead of using array notation.

> [!NOTE]
> argv[argc] is always `NULL`


## Environment variable

Here is some notes on [Beej's guide](https://beej.us/guide/bgc/html/split/the-outside-environment.html#env-var)

