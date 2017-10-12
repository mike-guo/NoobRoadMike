#include <iostream>
using namespace std;

void LCS_test() {  // 最长公共子序列 Longest Common Subsequence （不同于 最长公共子串 Longest Common Substring）
	string str1 = "2017 11 02";
	string str2 = "02 11 2017";

	int x_len = str1.length();
	int y_len = str2.length();

	int arr[50][50] = { {0, 0} };

	int i = 0;
	int j = 0;

	int res = 0;

	for(i = 1; i <= x_len; i++) {
		for(j = 1; j <= y_len; j++) {
			if(str1[i - 1] == str2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			} else {
				if(arr[i][j - 1] >= arr[i - 1][j]) {
					arr[i][j] = arr[i][j - 1];
				} else {
					arr[i][j] = arr[i -1][j];
				}
			}
		}
	}
	for(i = x_len, j = y_len; i >= 1 && j >= 1;) {
		if(str1[i - 1] == str2[j - 1]) {
			res++;
			i--; j--;
		} else {
			if(arr[i][j -1] > arr[i - 1][j])  j--;
			else  i--;
		}
	}
	cout << res << endl;
}