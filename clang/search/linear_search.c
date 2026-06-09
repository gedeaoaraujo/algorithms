#include <stdio.h>

int loop_search(int *arr, int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int recursive_search(int *arr, int n, int key) {
  if (n == 0) {
    return -1;
  }

  if (arr[n - 1] == key) {
    return n - 1;
  }

  return recursive_search(arr, n - 1, key);
}

int main() {
  int key = 30;
  int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
  int length = sizeof(arr) / sizeof(arr[0]);
  // int i = loop_search(arr, length, key);
  int i = recursive_search(arr, length, key);

  if (i == -1)
    printf("Key Not Found");
  else
    printf("Key Found at Index: %d", i);

  return 0;
}
