#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int get_number_prompt(const char *prompt);

int main(void)
{
    int letters, guesses;

    printf(
            "Keybordle!\n"
            "The goal is simple, find the secret keybordle by guessing\n"
            "Just enter a string of appropriate length and the computer will tell you if the letter in the alphabet is:\n"
            "After the letter you entered(1)\n"
            "Before the letter you entered(0)\n"
            "The same(the letter)\n"
          );
    letters = get_number_prompt("How many letters?\n");
    guesses = get_number_prompt("How long of a game?\n");
    printf("Letters: %d\n", letters);
    printf("Guesses: %d\n", guesses);
    return 0;
}

int get_number_prompt(const char *prompt)
{
    char buffer[BUFFER_SIZE], *newline;
    int burner;

    printf("%s", prompt);
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Failed to read string from stdin\n");
        exit(1);
    }
    newline = strchr(buffer, '\n');
    if (newline == NULL) {
        do {
            burner = getchar();
        } while (burner != '\n' && burner != EOF);
    } else {
        *newline = '\0';
    }
    return atoi(buffer);
}
