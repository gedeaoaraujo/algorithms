#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    bool swapped = false;

    for (int j = 0; j < length - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr + j, arr + j + 1);
        swapped = true;
      }
    }

    if (swapped == false) break;
  }
}

int main() {
  int arr[] = {6, 0, 3, 5};
  int length = (sizeof(arr) / sizeof(arr[0]) - 1);

  bubble_sort(arr, length);

  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);

  return 0;
}
