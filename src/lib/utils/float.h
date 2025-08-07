#pragma once
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool compare_float(void *a, void *b);
bool greather_float(void *a, void *b);
void float_toString(void *data, char *buffer);
void free_float(void *data);
void *make_float(va_list args);
