#include <iostream>
#include <string>
using namespace std;

void Group58_test() {  // 58集团笔试：url参数提取
	string str, res;
	cin >> str;
	int len = str.size();
	bool flag = false;
	int head = -1;
	string tmp;
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (!flag) {
				if (head > -1) {
					tmp += str.substr(head, i - head) + ' ';
					res += tmp;
				}
				head = i;
				flag = true;
			}
		} else if (str[i] >= '0' && str[i] <= '9') {
			if (flag) {
				tmp = str.substr(head, i - head) + '=';
				head = i;
				flag = false;
			}
		}
	}
	tmp += str.substr(head);
	res += tmp;
	cout << res << endl;
}