#include "./int.h"

bool compare_int(void *a, void *b) { return *(int *)a == *(int *)b; }

void int_toString(void *data, char *buffer) {
  sprintf(buffer, "%d", *(int *)data);
}

void free_int(void *data) { free(data); }

void *make_int(va_list args) {
  int value = va_arg(args, int);
  int *ptr = malloc(sizeof(int));
  *ptr = value;
  return ptr;
}

bool greather_int(void *a, void *b) { return *(int *)a > *(int *)b; }
