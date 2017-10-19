#include <iostream>
#include <time.h>
#include <algorithm>
#include "common.h"
using namespace std;

bool bigger(char a, char b) { return a > b; }

void CCBFund_test() {  // ���Ż�����ԣ�������ɲ��ظ�����ĸ���в���������
	bool flags[26] = { 0, };
	const int len = 20;
	char chars[len] = { 0, };
	srand(time(NULL));
	int i = 0;
	while (i < len) {
		char ch = rand() % 26;
		if (!flags[ch]) {
			chars[i] = ch + 'a';
			i++;
			flags[ch] = true;
		}
	}
	for_each(chars, chars + len, print_ch);
	cout << endl;
	sort(chars, chars + len, bigger);
	for_each(chars, chars + len, print_ch);
	cout << endl;
}