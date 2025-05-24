#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

Vector* vec_new(size_t size) {
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

bool vec_exists(Vector* vector) {
  if (vector == NULL) {
    printf("Vector is NULL\n");
    return false;
  } else if (vector->contents == NULL) {
    printf("Vector contents are NULL\n");
    return false;
  }
  return true;
}

int* vec_at(Vector* vector, size_t index) {
  if (!vec_exists(vector)) {
    return NULL;
  }
  if (index > vector->length) {
    printf("Index out of bounds\n");
    return NULL;
  }
  return &vector->contents[index];
}

// Appends an element to a `Vector`.
// Returns the new size of the vector, which remains unchanged if allocation fails.
size_t vec_append(Vector* vector, int element) {
  if (!vec_exists(vector)) {
    printf("Failed to append\n");
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

Vector* vec_delete(Vector* vector) {
  if (vector) {
    free(vector->contents);
    free(vector);
  }
  return NULL;
}

void vec_print(Vector* vector) {
  if (!vec_exists(vector)) {
    return;
  }
  printf("[ ");
  for (int i = 0; i < vector->length; i++) {
    printf("%d", vector->contents[i]);
    if (i + 1 < vector->length)
      printf(", ");
  }
  printf(" ]\n");
}

size_t vec_len(Vector* vector) {
  if (!vec_exists(vector)) {
    return 0;
  }
  return vector->length;
}
