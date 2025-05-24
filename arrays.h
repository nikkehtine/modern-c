#ifndef __MODERNC_ARRAYS_H
#define __MODERNC_ARRAYS_H

#include <stdio.h>
#include <stdlib.h>

// A `Vector` is a dynamic array that can grow and shrink.
// Use `new_vector(size_t size)` to create one.
struct Vector {
  size_t length;
  size_t capacity;
  int* contents;
};

struct Vector* new_vector(size_t size);

size_t append_vector(struct Vector* vector, int element);

void delete_vector(struct Vector* vector);

#endif
