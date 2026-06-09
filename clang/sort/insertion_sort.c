#include <math.h>
#include <stdio.h>

void insertion_sort(int arr[], int length) {
  for (int i = 1; i < length; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int length = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  insertion_sort(arr, length);

  printf("Sorted array: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
