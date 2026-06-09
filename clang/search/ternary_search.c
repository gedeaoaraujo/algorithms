#include <stdio.h>

int ternary_search(int arr[], int start, int end, int target) {
  if (start > end) {
    printf("Start index out of range");
    return -1;
  }

  int mid1 = start + (end - start) / 3;
  int mid2 = end - (end - start) / 3;

  if (arr[mid1] == target) return mid1;
  if (arr[mid2] == target) return mid2;

  if (target < arr[mid1]) {
    return ternary_search(arr, start, mid1 - 1, target);
  } else if (target > arr[mid2]) {
    return ternary_search(arr, mid2 + 1, end, target);
  } else {
    return ternary_search(arr, mid1 + 1, mid2 - 1, target);
  }
}

int main() {
  int target = 3;
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

  int length = sizeof(arr) / sizeof(arr[0]);
  int result = ternary_search(arr, 0, length - 1, target);

  if (result != -1)
    printf("Element %d found at index %d\n", target, result);
  else
    printf("Element %d not found in the array\n", target);

  return 0;
}
