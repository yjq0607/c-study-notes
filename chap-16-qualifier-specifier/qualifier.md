# Qualifier and specifier

## Const

You can `const` either the pointer itself or the value it points to, or both

```c
const int *p = &x;  // const the dereference value of p
int *const p = &x;  // const the pointer itself

const int *const p = &x;  // const both the value and the pointer
```

> [!WARNING]
> maybe it's not a good idea to const just `x` itself if there is a pointer pointing to it

```c
const int x = 10;
int *p = &x;  // compiler will through warning
// the behaviour would be undefined if writing to *p

```

## Others

Here is a brief summary on other qualifiers and specifiers

|  keyword | meaning | b |
| :---: | :---: | :---: |
| restrict | variable to be only accessed by one and only one pointer | qualifier |
| volatile | ever-updating variable beyond control of the code itself | qualifier |
| `_Atomic` | --- | qualifier |
| auto | implied, block scoped | specifier |
| static (block) | only initialises once and remain consist beyond blocks | specifier |
| static (file) | variable only accessible in current file | specifier |
| extern | variable from another file | specifier |
| register | to be stored in register, but compiler makes the call | specifier |
| `_Thread_local` | for multiple threads, make sure each thread gets its own var copy | specifier |

> [!TIP]
> TLDR learn `const`, `static`, `extern`
