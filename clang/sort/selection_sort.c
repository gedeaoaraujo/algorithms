#include <stdio.h>

void selection_sort(int arr[], int length) {
  for (int i = 0; i < length; i++) {

    int min_idx = i;
    for (int j = i + 1; j < length; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int length = (sizeof(arr) / sizeof(arr[0]) - 1);

  printf("Unsorted array: \n");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  selection_sort(arr, length);

  printf("Sorted array: \n");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  return 0;
}
