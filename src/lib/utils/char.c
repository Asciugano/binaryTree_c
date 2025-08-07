#include "./char.h"
#include <stdbool.h>

bool compare_char(void *a, void *b) { return *(char *)a == *(char *)b; }

void char_toString(void *data, char *buffer) {
  sprintf(buffer, "'%c'", *(char *)data);
}

void free_char(void *data) { free(data); }

void *make_char(va_list args) {
  char value = va_arg(args, int);
  char *ptr = malloc(sizeof(char));
  *ptr = value;
  return ptr;
}

bool greather_char(void *a, void *b) { return *(char *)a > *(char *)b; }
