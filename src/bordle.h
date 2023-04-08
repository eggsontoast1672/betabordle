#ifndef BORDLE_UTILS_H
#define BORDLE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Returns a heap-allocated buffer, so make sure to free it when you're done!
 */
char *randseqc(size_t length);

/**
 * Print an array of characters to stdout.
 */
void parrc(const char *array, size_t length);

#endif
