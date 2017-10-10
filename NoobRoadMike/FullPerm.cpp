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

void FullPerm_test() {
	FullPerm_test1();
	FullPerm_test2();
}