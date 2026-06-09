#include <stdio.h>

void heapify(int arr[], int n, int i) {
  int temp, maximum;
  int left_index, right_index;

  maximum = i;
  right_index = 2 * i + 2;
  left_index = 2 * i + 1;

  if (left_index < n && arr[left_index] > arr[maximum])
    maximum = left_index;

  if (right_index < n && arr[right_index] > arr[maximum])
    maximum = right_index;

  if (maximum != i) {
    temp = arr[i];
    arr[i] = arr[maximum];
    arr[maximum] = temp;
    heapify(arr, n, maximum);
  }
}

void heap_sort(int arr[], int n) {
  int i, temp;
  for (i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (i = n - 1; i > 0; i--) {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

int main() {
  int length = 6;
  int arr[] = {20, 18, 5, 15, 3, 2};

  printf("Original Array : ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  heap_sort(arr, length);

  printf("Array after performing heap sort: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
