#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

struct range {
	unsigned int left;
	unsigned int right;
};

void Didi_test() {  // 滴滴笔试：CIDR路由协议IP地址去重
	int n;
	cin >> n;
	vector<string> res;
	res.reserve(n);
	string str;
	vector<range> axis;
	axis.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		unsigned int num = 0;
		int head = 0, tail = 0;
		for (int j = 0; j < 4; j++) {
			tail = str.find(j < 3 ? '.' : '/', head);
			num = (num << 8) + atoi(str.substr(head, tail-head).c_str());
			head = tail + 1;
		}
		int cover = atoi(str.substr(head).c_str());

		unsigned int left, right;
		if (cover == 32) {
			left = num;
			right = num;
		} else {
			left = num & (0xffffffff << (32 - cover));
			right = left + (0xffffffff >> cover);
		}

		bool flag = true;
		for (vector<range>::iterator it = axis.begin(); it != axis.end();) {
			if (left >= it->left && right <= it->right) {
				flag = false;
				break;
			} else if (left <= it->left && right >= it->right) {
				it = axis.erase(it);
				res.erase(res.begin() + (it - axis.begin()));
				continue;
			}
			it++;
		}
		if (flag) {
			range ra = { left, right };
			axis.push_back(ra);
			res.push_back(str);
		}
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}