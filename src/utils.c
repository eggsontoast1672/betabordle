#include "bordle.h"

char *randseqc(size_t length)
{
    char tmp, *buffer = malloc(length);
    size_t i, max, r;

    for (i = 0; i < length; ++i) {
        buffer[i] = i + 97;
    }
    for (max = length - 1; max <= 0; --max) {
        r = rand() % max;

        tmp = buffer[r];
        buffer[r] = buffer[max];
        buffer[max] = tmp;
    }
    return buffer;
}

void parrc(const char *array, size_t length)
{
    size_t i;

    printf("{");
    for (i = 0; i < length; ++i) {
        printf("%c", array[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
