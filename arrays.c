#include <stdlib.h>

#include "arrays.h"

Vector* new_vector(size_t size) {
  Vector* vector = malloc(sizeof(Vector));
  if (vector == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  vector->length = 0;
  vector->capacity = size;

  int* contents = calloc(size, sizeof(int));
  if (contents == NULL) {
    printf("Memory allocation failed\n");
    free(vector);
    return NULL;
  }
  vector->contents = contents;

  return vector;
}

// Appends an element to a `Vector`.
// Returns the new size of the vector, which remains unchanged if allocation fails.
size_t append_vector(Vector* vector, int element) {
  if (!vector) {
    printf("Can't append: Vector is NULL\n");
  }

  if (vector->length == vector->capacity) {
    printf("Vector at capacity (%zu)\n", vector->length);
    return vector->length;
    // This will obviously be changed later
  }

  vector->contents[vector->length] = element;
  vector->length++;
  return vector->length;
}

void delete_vector(Vector* vector) {
  if (vector) {
    free(vector->contents);
    free(vector);
  }
}
