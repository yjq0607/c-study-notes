# Struct

Classes/objects don’t exist in C natively. You can think of a struct as a class with only data members, and no methods.\
For example,
```c
struct car {
    char *name;
    float price;
    int speed;
};


// Now with an initializer! Same field order as in the struct declaration:
struct car saturn = {"Saturn SL/2", 16000.99, 175};

// Or alternatively more specifically
struct car saturn = {.speed=175, .name="Saturn SL/2"};

printf("Name:      %s\n", saturn.name);
printf("Price:     %f\n", saturn.price);
printf("Top Speed: %d km\n", saturn.speed);
```


There are two cases when you'd want to pass a `pointer` to the `struct`:
1. You need the function to be able to make changes to the struct that was passed in, and have those changes show in the caller.
2. The struct is large and it's more expensive to copy that onto the stack than it is to just copy a pointer.

> [!NOTE]
> this means that passing the `struct` itself to a func is possible in C
