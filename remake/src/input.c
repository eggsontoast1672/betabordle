#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kbd_parse_string_int(const char *string, int *number)
{

}

void kbd_read_line(char *buffer, size_t size)
{
    char *newline;
    int c;

    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Failed to get string from stdin\n");
        exit(1);
    }
    newline = strchr(buffer, '\n');
    if (newline == NULL)
        do
            c = getchar();
        while (c != '\n' && c != EOF);
    else
        *newline = '\0';
}

void kbd_read_line_prompt(const char *prompt, char *buffer, size_t length)
{
    printf("%s", prompt);
    kbd_read_line(buffer, length);
}
