# Multi file

## include

> [!NOTE]
> this section is only for illustration
> for practical application, use [header file](#header-file)
You can include other files during compilation so scripts written somewhere else could be included.\

```c
// File bar.c

int add(int x, int y)
{
    return x + y;
}

```

```c
// File foo.c

#include <stdio.h>

int add(int, int)  // this is to avoid implicit declaration
                   // but this way it's too much trouble

int main()
{
    printf("%d\n", add(2, 3));  // 5!
}

```

> gcc -o output foo.c bar.c

> [!NOTE]
> the sequence between `foo.c` and `bar.c` does not matter


## header-file

You can create a header file with `.h` extension and to be included with `#include <bar.h>`\
Pay attention to `include guard` below.

### Include guard

This practice is in place when project grows large\
and the header file might be unnecessarily included more than once.\

In `bar.h`,

```c
#ifndef BAR_H   // If BAR_H isn't defined...
#define BAR_H   // Define it (with no particular value)

// File bar.h

int add(int x, int y)
{
    return x + y;
}

#endif          // End of the #ifndef BAR_H

```


```c
// File foo.c

#include <stdio.h>

// #include <bar.h>
#include "bar.h"  // bar.h is a file and should be quoted instead

int main()
{
    printf("%d\n", add(2, 3));  // 5!
}

```

## Object file

> [!TIP]
> if there are too many files, the compilation could take very long time
> especially updates on a few file and recompiling all of them from scratch
> it may be useful to generate object file and only regenerate object files for updated files


> gcc -c foo.c
> gcc -c bar.c
Yielding `foo.o` and `bar.o`

> [!NOTE]
> header file `.h` is not required to be made into object files

> gcc -o foo.o bar.o

