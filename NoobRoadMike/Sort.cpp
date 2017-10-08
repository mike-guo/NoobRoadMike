


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