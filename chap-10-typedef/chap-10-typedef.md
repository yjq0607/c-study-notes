# typedef

`typedef` creates an alias for the datatype.
```c
typedef int antelope, bagel, mushroom;  // These are all "int"

mushroom x = 10;  // same as int x = 10;

```

## Struct

This is most useful in `struct`

### typedef struct

```c
struct animal {
    char *name;
    int leg_count, speed;
};

//  original name      new name
//            |         |
//            v         v
//      |-----------| |----|
typedef struct animal animal;

struct animal y;  // This works
animal z;         // This also works because "animal" is an alias


/* Alternatively */
typedef struct animal {
    char *name;
    int leg_count, speed;
} animal;  

```


### Anonymous struct

```c
//  Anonymous struct! It has no name!
//         |
//         v
//      |----|
typedef struct {
    char *name;
    int leg_count, speed;
} animal;                         // <-- new name

//struct animal y;  // ERROR: this no longer works--no such struct!
animal z;           // This works because "animal" is an alias
```


## Quick change if different type is needed

> [!TIP]
> If the code has been using the same type at different place and changing the type is needed\
> it might be useful to set a custom `typedef`


```c
typedef float app_float;
// if update is needed
typedef long double app_float;
// then you don't need to update the body of the code


app_float f1, f2, f3;
```

