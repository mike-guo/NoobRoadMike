#include <iostream>
#include <time.h>
#include <algorithm>
#include "common.h"
using namespace std;

bool bigger(char a, char b) { return a > b; }

void CCBFund_test() {  // ���Ż�����ԣ�������ɲ��ظ�����ĸ���в���������
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