#include <stdio.h>

int loop_search(int arr[], int start, int end, int key) {
  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {
      return mid;
    }

    if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
}

int recursive_search(int arr[], int start, int end, int value) {
  if (end < start){
    printf("Index out of range");
    return -1;
  }

  int mid = start + (end - start) / 2;
  if (arr[mid] == value) return mid;

  if (arr[mid] > value)
    return recursive_search(arr, start, mid - 1, value);

  return recursive_search(arr, mid + 1, end, value);
}

int main() {
  int value = 23;
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int size = sizeof(arr) / sizeof(arr[0]);
  // int result = loop_search(arr, 0, size - 1, key);
  int result = recursive_search(arr, 0, size - 1, value);

  if (result == -1) {
    printf("Element is not present in array");
  } else {
    printf("Element is present at index %d", result);
  }
  return 0;
}
