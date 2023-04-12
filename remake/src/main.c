#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input.h"
#include "keybordle.h"

int main(void)
{
    int letters, guesses;

    kbd_print_introduction();

    letters = kbd_get_num_letters();
    guesses = kbd_get_num_guesses();

    printf("Letters: %d\n", letters);
    printf("Guesses: %d\n", guesses);

    return 0;
}
