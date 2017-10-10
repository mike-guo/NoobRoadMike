#include "common.h"
#include <algorithm>
using namespace std;

void swap_int(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void FullPerm(int* arr, int head, int tail) {  // ȫ����
	if (head == tail) {
		for_each(arr, arr + 4, print_int);
		cout << endl;
		return;
	}
	for (int i = head; i <= tail; i++) {
		swap_int(arr[head], arr[i]);
		FullPerm(arr, head + 1, tail);
		swap_int(arr[head], arr[i]);  // ����
	}
}

void FullPerm_test1() {
	int arr[4] = { 1, 2, 3, 4 };
	FullPerm(arr, 0, 3);
}

void FullPerm_test2() {  // ����STL�ṩ��next_permutation����ʵ��
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