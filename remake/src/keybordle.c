#include "keybordle.h"

#include <stdio.h>
#include <stdlib.h>

#include "input.h"

#define BUFFER_SIZE 32

int kbd_get_num_guesses(void)
{
    char buffer[BUFFER_SIZE];
    int guesses;

    kbd_read_line_prompt("How long a game?\n", buffer, BUFFER_SIZE);
    if (kbd_parse_string_int(buffer, &guesses) != 0) {
#ifdef DEBUG
        fprintf(stderr, "[DEBUG] Remove this!\n");
#endif
        printf("Invalid guess!\n");
        exit(1);
    }
    return guesses;
}

int kbd_get_num_letters(void)
{
    return 0;
}

void kbd_print_introduction(void)
{
    printf("Keybordle!\n");
    printf("The goal is simple, find the secret keybordle by guessing\n");
    printf("Just enter a string of appropriate length and the computer will tell you if the letter in the alphabet is:\n");
    printf("After the letter you entered(1)\n");
    printf("Before the letter you entered(0)\n");
    printf("The same(the letter)\n");
}
