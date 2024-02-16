# sprintfa 
Combine variable length arrays in C99 and sprintf into new function.

The sprintfa function uses variable length arrays in C99 to create
a buffer from c-stack RAM of exactly the right size and perform a
sprintf into that buffer. This prevents buffer overflows.

To use this function, declare a character which will be the array name
as part of the sprintfa() function:

    #include "sprintfa.h"

    char sprintfa(x, "Hello World\n");
    printf("%s\n", x);

Special thanks to [Sam](https://blog.sam.liddicott.com/2015/07/marriage-of-alloca-and-asprintf.html) for the details.
