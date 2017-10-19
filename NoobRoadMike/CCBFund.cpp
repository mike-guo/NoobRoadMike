#include <iostream>
#include <time.h>
#include <algorithm>
#include "common.h"
using namespace std;

bool bigger(char a, char b) { return a > b; }

void CCBFund_test() {  // 建信基金笔试：随机生成不重复的字母序列并逆序排序
	bool flags[26] = { false, };
	char chars[20] = { 0, };
	srand((unsigned)time(NULL));
	int i = 0;
	while (i < 20) {
		char ch = rand() % 26;
		if (!flags[ch]) {
			chars[i] = ch + 'a';
			i++;
			flags[ch] = true;
		}
	}
	for_each(chars, chars + 20, print_ch);
	cout << endl;
	sort(chars, chars + 20, bigger);
	for_each(chars, chars + 20, print_ch);
	cout << endl;
}