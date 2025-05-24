#include <stdio.h>

#include "arrays.h"

int main() {
  printf("\n");

  printf("Modern C library showcase!\n");
  printf("--------------------------\n");

  //   Dynamic arrays
  int num_of_vec_elements = 4;  // Play with this number

  //   Create
  Vector* my_arr = vec_new(num_of_vec_elements);
  if (my_arr == NULL) {
    printf("ERROR: failed vector allocation\n");
    return 1;
  }

  //   Append
  printf("\n:: Appending %d elements to the array\n", num_of_vec_elements);
  printf("------------------------------------\n");

  printf("-- Input:\n");
  printf("   ");
  printf("[ ");
  for (int i = 0; i < num_of_vec_elements; i++) {
    vec_append(my_arr, i);
    if (i > 0)
      printf(", ");
    printf("%d", i);
  }
  printf(" ]\n");
  printf("\n");

  printf("-- Output:\n");
  printf("   ");
  vec_printr(my_arr);

  //   Access element
  printf("\n:: Accessing the array\n");
  printf("----------------------\n");

  if (my_arr == NULL) {
    printf("Array is deleted\n");
  } else {
    size_t len = my_arr->length;
    printf("%zu elements, last element is %d\n", len, *vec_at(my_arr, len - 1));
  }

  //   Delete
  printf("\n:: Deleting the array\n");
  printf("---------------------\n");

  printf("-- Input:\n");
  if (my_arr == NULL) {
    printf("   Array is deleted\n");
  } else {
    size_t len = my_arr->length;
    printf("   Array exists; last element is %d\n", *vec_at(my_arr, len - 1));

    printf("   ");
    vec_printr(my_arr);
  }
  printf("\n");

  my_arr = vec_delete(my_arr);

  printf("-- Output:\n");
  if (my_arr == NULL) {
    printf("   Array is deleted\n");
  } else {
    size_t len = my_arr->length;
    printf("   Array exists; last element is %d\n", *vec_at(my_arr, len - 1));

    printf("   ");
    vec_printr(my_arr);
  }
  printf("\n");
}
