#include <stdio.h>
#include <string.h>
#define RANGE 255

void count_sort(char arr[]) {
  int index = 0;
	int count[RANGE + 1];
	char output[strlen(arr)];

	memset(count, 0, sizeof(count));

	for(index = 0; arr[index]; ++index)
		++count[arr[index]];

	for (index = 1; index <= RANGE; ++index)
		count[index] += count[index-1];

	for (index = 0; arr[index]; ++index) {
		output[count[arr[index]]-1] = arr[index];
		--count[arr[index]];
	}

	for (index = 0; arr[index]; ++index)
		arr[index] = output[index];
}

int main(){
	char arr[] = "geeksforgeeks";
	count_sort(arr);

	printf("Sorted character array is %sn", arr);
	return 0;
}
