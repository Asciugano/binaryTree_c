#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool compare_char(void *a, void *b);
bool greather_char(void *a, void *b);
void char_toString(void *data, char *buffer);
void free_char(void *data);
void *make_char(va_list args);
