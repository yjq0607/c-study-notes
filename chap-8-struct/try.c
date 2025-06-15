#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *p, float target_price)
{
    // *p.price = target_price;  // turns out that (*p).price works but ugly
    p->price = target_price;
}


int main(void)
{
    struct car saturn = {.speed=175, .name="Saturn SL/2"};

    // Pass a pointer to this struct car, along with a new,
    // more realistic, price:
    set_price(&saturn, 799.99);

    printf("Price: %f\n", saturn.price);
}

