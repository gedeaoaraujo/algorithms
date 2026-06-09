#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int p = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (arr[i] <= p && i <= high - 1) { i++; }
    while (arr[j] > p && j >= low + 1) { j--; }
    if (i < j) { swap(&arr[i], &arr[j]); }
  }

  swap(&arr[low], &arr[j]);
  return j;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {4, 2, 5, 3, 1};
  int length = sizeof(arr) / sizeof(arr[0]);

  // calling quickSort() to sort the given array
  quick_sort(arr, 0, length - 1);

  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);

  return 0;
}
