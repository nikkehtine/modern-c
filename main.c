#include <stdio.h>

#include "arrays.h"

int main() {
  printf("Modern C library showcase!\n");
  printf("--------------------------\n");

  //   Vectors
  int num_of_vec_elements = 4;  // Play with this number

  Vector* my_arr = new_vector(num_of_vec_elements);
  if (my_arr == NULL) {
    printf("ERROR: failed vector allocation\n");
    return 1;
  }

  printf("Appending %d elements to the array\n", num_of_vec_elements);
  printf("Input:\n");
  printf("[ ");
  for (int i = 0; i < num_of_vec_elements; i++) {
    int num = i + 1;
    append_vector(my_arr, num);
    if (i > 0)
      printf(", ");
    printf("%d", num);
  }
  printf(" ]\n");

  printf("Output:\n");
  printf("[ ");
  for (int i = 0; i < my_arr->length; i++) {
    printf("%d", my_arr->contents[i]);
    if (i + 1 < my_arr->length)
      printf(", ");
  }
  printf(" ]\n");
}
