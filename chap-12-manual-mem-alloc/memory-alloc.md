# Memory Allocation

## malloc()

`malloc` takes number of bytes as argument

| | explain |
| :---: | :---: |
| arg | bytes, suggest number of element * sizeof(ele type) |
| return | `void` type pointer or `null` if unsuccessful |


## calloc()

`calloc` takes 2 arguments

|  | explain |
| :---: | :---: |
| arg1 | number of elements |
| arg2 | size in byte of each element |
| return | `void` type pointer or `null` if unsuccessful |


## realloc()

`return` takes  2 arguments

|  | explain |
| :---: | :---: |
| arg1 | pointer to the array |
| arg2 | size in bytes the new memory size required (reduce/increase) |


```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate space for 20 floats
    float *p = malloc(sizeof *p * 20);  // sizeof *p same as sizeof(float)

    // Assign them fractional values 0.0-1.0:
    for (int i = 0; i < 20; i++)
        p[i] = i / 20.0;

    // But wait! Let's actually make this an array of 40 elements
    float *new_p = realloc(p, sizeof *p * 40);

    // Check to see if we successfully reallocated
    if (new_p == NULL) {
        printf("Error reallocing\n");
        return 1;
    }

    // If we did, we can just reassign p
    p = new_p;

    // And assign the new elements values in the range 1.0-2.0
    for (int i = 20; i < 40; i++)
        p[i] = 1.0 + (i - 20) / 20.0;

    // Print all values 0.0-2.0 in the 40 elements:
    for (int i = 0; i < 40; i++)
        printf("%f\n", p[i]);

    // Free the space
    free(p);
}

```


### Growing and shrinking buffer according to need

example from Beej's

```c
#include <stdio.h>
#include <stdlib.h>

// Read a line of arbitrary size from a file
//
// Returns a pointer to the line.
// Returns NULL on EOF or error.
//
// It's up to the caller to free() this pointer when done with it.
//
// Note that this strips the newline from the result. If you need
// it in there, probably best to switch this to a do-while.

char *readline(FILE *fp)  // function to be called for each "line"
{
    int offset = 0;   // Index next char goes in the buffer
    int bufsize = 4;  // Preferably power of 2 initial size
    char *buf;        // The buffer
    int c;            // The character we've read in

    buf = malloc(bufsize);  // Allocate initial buffer, arbitary 4 bytes here
    if (buf == NULL)   // Error check for malloc
        return NULL;

    // Main loop--read until newline or EOF
    while (c = fgetc(fp), c != '\n' && c != EOF) {

        // Check if we're out of room in the buffer accounting
        // for the extra byte for the NUL terminator
        // buf[offset] writes the char, so bufsize with NUL terminator is 1 byte larger than offset
        if (offset == bufsize - 1) {  // When offset catches up with bufsize

            bufsize *= 2;  // 2x the space
            char *new_buf = realloc(buf, bufsize);
            if (new_buf == NULL) {  // realloc error check
                free(buf);   // On error, free and bail
                return NULL;
            }

            buf = new_buf;  // Successful realloc
        }

        buf[offset++] = c;  // Add the byte onto the buffer
    }

    // We hit newline or EOF...

    // If at EOF and we read no bytes, free the buffer and
    // return NULL to indicate we're at EOF:
    if (c == EOF && offset == 0) {
        free(buf);
        return NULL;
    }

    // Shrink to fit
    if (offset < bufsize - 1) {  // if bufsize without NUL terminator is still larger than offset

        char *new_buf = realloc(buf, offset + 1); // +1 for NUL terminator
        // If successful, point buf to new_buf;
        // otherwise we'll just leave buf where it is
        if (new_buf != NULL)
            buf = new_buf;
    }

    // Add the NUL terminator
    buf[offset] = '\0';

    return buf;  // note that "buf" is a malloc pointer, caller is required to free it
}

int main(void)
{
    FILE *fp = fopen("foo.txt", "r");

    char *line;

    while ((line = readline(fp)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);
}

```

