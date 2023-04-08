#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bordle.h"

#define MAXSEQ 5

int main(void)
{
    char *sequence;

    srand(time(NULL));
    sequence = randseqc(MAXSEQ);
    parrc(sequence, MAXSEQ);
    free(sequence);

    return 0;
}
