#include "./float.h"

bool compare_float(void *a, void *b) { return *(float *)a == *(float *)b; }

void float_toString(void *data, char *buffer) {
  sprintf(buffer, "%.2f", *(float *)data);
}

void free_float(void *data) { free(data); }

void *make_float(va_list args) {
  float value = va_arg(args, double);
  float *ptr = malloc(sizeof(float));
  *ptr = value;
  return ptr;
}

bool grather_float(void *a, void *b) { return *(float *)a > *(float *)b; }
