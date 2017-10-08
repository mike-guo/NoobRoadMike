#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(string& str, vector<string>& vec) {
	int head = 0, tail = str.find('/');
	while (tail != string::npos) {
		vec.push_back(str.substr(head, tail - head));
		head = tail + 1;
		tail = str.find('/', head);
	}
	if (head != str.length()) 
		vec.push_back(str.substr(head));
}