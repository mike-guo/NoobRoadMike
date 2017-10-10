#include "common.h"
#include <algorithm>

void QuickSort(int* arr, int head, int tail) {
	if (head >= tail)  return;
	int i = head, j = tail;
	int tmp = arr[i];
	while (i < j) {
		while (i < j && tmp <= arr[j])  j--;
		if (i < j) {
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] <= tmp)  i++;
		if (i < j) {
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = tmp;
	QuickSort(arr, head, i - 1);
	QuickSort(arr, i + 1, tail);
}

void Sort_test() {
	int arr[10] = { 3, 9, 2, 5, 1, 0, 7, 4, 6, 8 };
	for_each(arr, arr + 10, print_int);
	cout << endl;
	QuickSort(arr, 0, 9);
	for_each(arr, arr + 10, print_int);
	cout << endl;
}