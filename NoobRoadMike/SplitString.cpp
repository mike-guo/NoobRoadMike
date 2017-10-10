#include <iostream>
#include <string>
#include <vector>
using namespace std;

void splitStr(string& str, vector<string>& vec, char sig) {
	int head = 0, tail = str.find(sig);
	while (tail != string::npos) {
		vec.push_back(str.substr(head, tail - head));
		head = tail + 1;
		tail = str.find(sig, head);
	}
	if (head != str.length()) 
		vec.push_back(str.substr(head));
}

void SplitString_test() {
	string str;
	cin >> str;
	vector<string> res;
	splitStr(str, res, '.');
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}