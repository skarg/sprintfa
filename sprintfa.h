/**
 * @file
 * @author Steve Karg
 * @date February 2024
 * @brief Marriage of variable length arrays in C99 and sprintf as sprintfa
 *
 * @section DESCRIPTION
 *
 * The sprintfa function uses variable length arrays in C99 to create
 * a buffer from c-stack RAM of exactly the right size and perform a
 * sprintf into that buffer. This prevents buffer overflows.
 *
 * To use this function, declare a character which will be the array name
 * as part of the sprintfa() function:
 * {@code
 * char sprintfa(x, "Hello World\n");
 * printf("%s\n", x);
 * }
 *
 * Note: The variable length arrays in C99 allocates memory space in
 * the stack frame of the caller.  This temporary space is automatically
 * freed when the function returns to its caller.
 */
#ifndef _SPRINTFA_H_
#define _SPRINTFA_H_
#include <stdio.h>

/**
 * @brief function to use c-stack RAM to create a string within function scope
 * @param c - variable length array char name
 * @param ... - vsprintf format specifiers and variable arguments
 */
#define sprintfa(c, ...) \
  c[1 + snprintf(NULL, 0, __VA_ARGS__)]; \
  sprintf(c, __VA_ARGS__)

#endif
