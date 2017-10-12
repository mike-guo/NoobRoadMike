#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calcStr(string str) {
	if (str[0] == '0')  return 0;
	int len = str.size();
	if (len == 1)  return 1;
	if (len == 2) {
		if (str[0] == '1') {
			if (str[1] == '0')  return 1;
			else  return 2;
		} else {  // str[0] == '2'
			if (str[1] == '0' || str[1] > '6')  return 1;
			else  return 2;
		}
	}
	return calcStr(str.substr(1)) + calcStr(str.substr(2));
}

void SenseTime_test1() {  // 商汤笔试1：数字->字母译码
	string str;
	cin >> str;
	vector<string> vec;
	int head = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] > '2' || str[i] == '0') {
			vec.push_back(str.substr(head, i - head + 1));
			head = i + 1;
		}
	}
	if (head != len) {
		vec.push_back(str.substr(head, len - head));
	}
	int res = 1;
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		res *= calcStr(vec[i]);
	}
	cout << res << endl;
}

void SenseTime_test2() {  // 商汤笔试2：二值图像去噪（没做出来。。）
	int m, n;
	cin >> m >> n;
	// vector的vector 声明方法
	vector<vector<int>> vec(m, vector<int>(n, 2));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << vec[i][j] << ' ';
		}
		cout << endl;
	}
}

void SenseTime_test() {
	SenseTime_test1();
	//SenseTime_test2();
}