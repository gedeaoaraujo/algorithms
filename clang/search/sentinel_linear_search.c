#include <stdio.h> 

int sentinel_linear_search(int arr[], int length, int target) { 
	int last_value = arr[length]; 
	arr[length] = target; 

	int index = 0; 
	while (arr[index] != target) { 
		index++; 
	}

	arr[length] = last_value;

	if (index < length || arr[length] == target) { 
		return index;
	} else { 
		return -1;
	} 
} 

int main() { 
	int target = 8; 
	int arr[] = { 3, 5, 1, 8, 2 }; 
	int length = (sizeof(arr) / sizeof(arr[0])) - 1; 
	int result = sentinel_linear_search(arr, length, target); 

	if (result != -1) { 
		printf("Element %d found at index %d\n", target, result); 
	} else { 
		printf("Element %d not found\n", target); 
	} 

	return 0; 
}
