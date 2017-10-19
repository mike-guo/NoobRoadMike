#include "common.h"
#include <algorithm>
using namespace std;

void swap_int(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void FullPerm(int* arr, int head, int tail) {  // 全排列
	if (head == tail) {
		for_each(arr, arr + 4, print_int);
		cout << endl;
		return;
	}
	for (int i = head; i <= tail; i++) {
		swap_int(arr[head], arr[i]);
		FullPerm(arr, head + 1, tail);
		swap_int(arr[head], arr[i]);  // 回溯
	}
}

void FullPerm_test1() {
	int arr[4] = { 1, 2, 3, 4 };
	FullPerm(arr, 0, 3);
}

void FullPerm_test2() {  // 利用STL提供的next_permutation方法实现
	int arr[3] = {2, 1, 3};
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	sort(arr, arr+3);
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

	cout << next_permutation(arr, arr+3) << '\n';
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
}

bool GetNextPerm(int * arr, int len) {  // 腾讯面试：实现next_permutation功能
	if (len <= 1)  return false;
	int index = len - 1;
	for ( ; index > 0; index--) {
		if (arr[index - 1] < arr[index])  break;
	}
	if (index == 0) {
		sort(arr, arr + len);
		return false;
	}
	int i = index;
	for ( ; i < len - 1; i++) {
		if (arr[index - 1] < arr[i] && arr[index - 1] > arr[i + 1])  break;
	}
	swap_int(arr[index - 1], arr[i]);
	for (int i = index, j = len - 1; i < j; i++, j--) {
		swap_int(arr[i], arr[j]);
	}
	return true;
}

void FullPerm_test3() {
	int count = 1;
	int arr[5] = { 3, 1, 4, 2, 5 };
	cout << count << ": ";
	for_each(arr, arr + 5, print_int);
	cout << endl;
	while (GetNextPerm(arr, 5)) {
		count++;
		cout << count << ": ";
		for_each(arr, arr + 5, print_int);
		cout << endl;
	}
	for_each(arr, arr + 5, print_int);
	cout << endl;
}

void FullPerm_test() {
	//FullPerm_test1();
	//FullPerm_test2();
	FullPerm_test3();
}