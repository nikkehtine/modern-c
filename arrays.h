#ifndef __MODERNC_ARRAYS_H
#define __MODERNC_ARRAYS_H

#include <stdio.h>
#include <stdlib.h>

// A `Vector` is a dynamic array that can grow and shrink.
// Use `new_vector(size_t size)` to create one.
typedef struct Vector {
  size_t length;
  size_t capacity;
  int* contents;
} Vector;

Vector* new_vector(size_t size);

size_t append_vector(Vector* vector, int element);

Vector* delete_vector(Vector* vector);

void print_debug_vector(Vector* vector);

#endif
