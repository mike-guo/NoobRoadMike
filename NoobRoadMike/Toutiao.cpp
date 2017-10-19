#include <iostream>
#include <vector>
using namespace std;

void Toutiao_test() {  // 头条笔试：求房间原有人数  // TODO: 这种方案不完备，通过率只有50%
	int n, x;
	cin >> n >> x;
	vector<int> vec(n, 0);
	int num;
	int min = 1000000001, min_i = -1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec[i] = num;
		if (num <= min) {
			min = num;
			min_i = i;
		}
	}
	if (x - 1 == min_i) {
		for (int i = 0; i < n; i++) {
			if (i == min_i) cout << min_i * n;
			else  cout << vec[i] - min;
			if (i < n - 1)  cout << ' ';
		}
		cout << endl;
	}
	if (x - 1 > min_i) {
		for (int i = 0; i < n; i++) {
			if (i < min_i || i > x - 1) cout << vec[i] - min;
			else if (i == min_i)  cout << min * n + (x - 1 - min_i);
			else  cout << vec[i] - min - 1;
			if (i < n - 1)  cout << ' ';
		}
		cout << endl;
	}
	if (x - 1 < min_i) {
		for (int i = 0; i < n; i++) {
			if (i < min_i && i > x - 1) cout << vec[i] - min;
			else if (i == min_i)  cout << min * n + (n + x - 1 - min_i);
			else  cout << vec[i] - min - 1;
			if (i < n - 1)  cout << ' ';
		}
		cout << endl;
	}
}
