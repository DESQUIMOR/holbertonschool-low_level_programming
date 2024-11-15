#ifndef main_H
#define main_H

#include <stdlib.h>

int _putchar(char c);
void reset_to_98(int *n);
void swap_int(int *a, int *b);
size_t _strlen(const char *str);
void _puts(char *str);
void print_rev(char *s);
void rev_string(char *s);
void puts2(char *str);
void puts_half(char *str);
void print_array(int *a, int n);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
void generate_key(void);
char *rot13(char *s);
void print_number(int n);
char *infinite_add(char *n1, char *n2, char *r, int size_r);
void set_string(char **s, char *to);

#endif
