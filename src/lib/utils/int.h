#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool compare_int(void *a, void *b);
bool greather_int(void *a, void *b);
void int_toString(void *data, char *buffer);
void free_int(void *data);
void *make_int(va_list args);
