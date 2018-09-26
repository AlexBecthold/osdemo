#include <stdio.h>
#include <stdlib.h>

void double_alloc(int ** arr, int * size);

int main(int argc, char* argv[]) {
  int arr_size = 15;
  int * my_array = malloc(arr_size*sizeof(int));
  for(int i=0; i<arr_size; i++) {
    my_array[i] = i * i+3;
  }

  printf("my_array: ");
  for(int i=0; i<arr_size; i++) {
    printf("%d ", my_array[i]);
  }
  printf("\n");

  double_alloc(&my_array, &arr_size);
  free(my_array);

  return 0;
}

void double_alloc(int ** arr, int * size) {
  int * temp = *arr;
  *arr =  malloc((*size) * 2 * sizeof(int));
  for(int i=0; i<*size; i++) {
    (*arr)[i] = temp[i];
  }
  free(temp);
  (*size) *= 2;
}
