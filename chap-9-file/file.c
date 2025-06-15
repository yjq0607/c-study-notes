#include <stdio.h>


int main(void)
{
    FILE *fp;

    fp = fopen("hello.txt", "r");
    int content = fgetc(fp);
    printf("%c\n", content);

    fclose(fp);

    return 0;
}

