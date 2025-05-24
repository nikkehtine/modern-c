#include <stdio.h>

#include "arrays.h"

int main() {
  printf("\n");

  printf("Modern C library showcase!\n");
  printf("--------------------------\n");

  //   Dynamic arrays
  int num_of_vec_elements = 4;  // Play with this number

  Vector* my_arr = new_vector(num_of_vec_elements);
  if (my_arr == NULL) {
    printf("ERROR: failed vector allocation\n");
    return 1;
  }

  printf("\n:: Appending %d elements to the array\n", num_of_vec_elements);

  printf("\n-- Input:\n");
  printf("[ ");
  for (int i = 0; i < num_of_vec_elements; i++) {
    int num = i + 1;
    append_vector(my_arr, num);
    if (i > 0)
      printf(", ");
    printf("%d", num);
  }
  printf(" ]\n");

  printf("\n-- Output:\n");
  print_debug_vector(my_arr);

  printf("\n:: Deleting the array\n");

  printf("\n-- Input:\n");
  if (my_arr == NULL) {
    printf("Array is deleted\n");
  } else {
    printf("Array exists; last element is %d\n", my_arr->contents[my_arr->length - 1]);
  }
  print_debug_vector(my_arr);

  my_arr = delete_vector(my_arr);

  printf("\n-- Output:\n");
  if (my_arr == NULL) {
    printf("Array is deleted\n");
  } else {
    printf("Last element is %d\n", my_arr->contents[my_arr->length]);
  }
  print_debug_vector(my_arr);

  printf("\n\n");
}
