#ifndef KBD_INPUT_H
#define KBD_INPUT_H

#include <stddef.h>

int kbd_parse_string_int(const char *string, int *number);
void kbd_read_line(char *buffer, size_t size);
void kbd_read_line_prompt(const char *prompt, char *buffer, size_t length);

#endif
