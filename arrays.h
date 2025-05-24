#ifndef __MODERNC_ARRAYS_H
#define __MODERNC_ARRAYS_H

#include <stdbool.h>
#include <stdlib.h>

// A `Vector` is a dynamic array that can grow and shrink.
// Use `vec_new(size_t size)` to create one.
typedef struct Vector {
  size_t length;
  size_t capacity;
  int* contents;
} Vector;

Vector* vec_new(size_t size);
bool vec_exists(Vector* vector);
int* vec_at(Vector* vector, size_t index);
size_t vec_append(Vector* vector, int element);
Vector* vec_delete(Vector* vector);
void vec_print(Vector* vector);
size_t vec_len(Vector* vector);

#endif
