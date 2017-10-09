#include "common.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_int(int x) {cout << x << " ";};
void print_str(string str) {cout << str << endl;};


int main() {
	//cout << hex << (0xffffffff >> 16) << endl;
	Didi_test();
	system("pause");
	return 0;
}



void swap_int(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void FullPerm(int* arr, int head, int tail) {
	if (head == tail) {
		for_each(arr, arr + 4, print_int);
		cout << endl;
		return;
	}
	for (int i = head; i <= tail; i++) {
		swap_int(arr[head], arr[i]);
		//cout << "FullPrem" << endl;
		FullPerm(arr, head + 1, tail);
		swap_int(arr[head], arr[i]);
	}
}

//int main() {
//	int arr[4] = { 1, 2, 3, 4 };
//	//cout << "FullPerm" << endl;
//	FullPerm(arr, 0, 3);
//	system("pause");
//	return 0;
//}


//int main() {
//	int arr[3] = {2, 1, 3};
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	sort(arr, arr+3);
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//	
//	cout << next_permutation(arr, arr+3) << '\n';
//	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
//
//	system("pause");
//	return 0;
//}


int canArrangeWords(int num,char** arr){
	if (num == 1)  return 1;
	int flags[26] = { 0 };
	for (int i = 0; i < num; i++) {
		cout << arr[i] << endl;
		flags[arr[i][0] - 'a']++;
		flags[arr[i][strlen(arr[i]) - 1] - 'a']--;
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < 26; i++) {
		if (flags[i] < 0)  cnt1 += (-flags[i]); 
		else if (flags[i] > 0)  cnt2 += flags[i];
	}
	if (cnt1 <= 1 && cnt2 <= 1)  return 1;
	else  return -1;
}

//int main(){
//	char* str[100] = { NULL };
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		str[i] = new char[100];
//		cin >> str[i];
//	}
//	std::cout << canArrangeWords(num, str) << endl;
//	system("pause");
//	return 0;
//}




//int main() {
//	int arr[10] = { 5, 2, 7, 0, 8, 1, 6, 3, 9, 4 };
//	for_each(arr, arr + 10, print);
//	cout << endl;
//	QuickSort(arr, 0, 9);
//	for_each(arr, arr + 10, print);
//	cout << '\n' << endl;
//
//	vector<int> nums;
//	//nums.reserve(10);
//	nums.resize(10);
//	nums.push_back(1);
//	cout << nums.size() << endl;
//	for_each(nums.begin(), nums.end(), print);
//	cout << '\n' << endl;
//	
//	vector<string> vec;
//	string t;
//	string str = "99";
//	cout << str.length() << ' ' << str.size() << endl;
//	cout << endl;
//	char sz[100] = "44";
//	str += sz;
//	cout << str << endl;
//	str = "mike";
//	cout << str << endl;
//	
//	cin >> str >> t;
//	cout << str << " == " << t << " | " << (str == t) << " | " << (str.compare(t)) << endl;
//	/*split(str.substr(1), vec);
//	for_each(vec.begin(), vec.end(), print);
//	cout << (str == vec[1]) << endl;*/
//	system("pause");
//	return 0;
//}


struct Bill {
	int t;
	int d;
};

int get_happy_lose(vector<Bill>& vec) {
	int sum_t = 0, happy_lose = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum_t += vec[i].t;
		if (sum_t <= vec[i].d)  continue;
		happy_lose += (sum_t - vec[i].d);
	}
	return happy_lose;
}

//int main() {
//	/*int n;
//	cin >> n;
//	vector<Bill> vec(15);
//	for (int i = 0; i < n; i++) {
//	cin >> vec[i].t >> vec[i].d;
//	}
//	int happy_lose = get_happy_lose(vec);
//	cout << 100 * n - happy_lose << endl;*/
//	vector<int> vec(15);
//	cout << vec.size() << vec.capacity();
//	system("pause");
//	return 0;
//}

long long fact_num[21] = { 1 };

void init_fact() {
	for (int i = 1; i <= 20; i++)  fact_num[i] = fact_num[i - 1] * i;
}

long long Anm(int n, int m) {
	if (n < 0 || m < 0 || n < m)  return 0;
	return fact_num[n] / fact_num[n - m];
} 

long long Cnm(int n, int m) {
	if (n < 0 || m < 0 || n < m)  return 0;
	return fact_num[n] / fact_num[n - m] / fact_num[m];
} 

//int main() {
//	init_fact();
//	int n, m;
//	cin >> n >> m;
//	cout << "Anm=" << Anm(n, m) << '\n'
//		<< "Cnm=" << Cnm(n, m) << endl;
//	return 0;
//}


int calcMaxLen(int size, int allowedChanges, char* str) {
	int len = 0;
	while (len < size) {
		if (str[len] == '1') {
			while (len < size && str[len] == '1') {
				len++; 
			}
		} else {
			if (allowedChanges == 0)  break;
			while (len < size && str[len] == '0' && allowedChanges > 0) {
				allowedChanges--;
				len++;
			}
		}
	}
	return len;
}
int findDifferentWays(int size, int allowedChanges, char* str)         
{
	int maxLen = 0;
	int maxWays = 0;
	for (int off = 0; off <= size - allowedChanges; off++) {
		int len = calcMaxLen(size - off, allowedChanges, str + off);
		if (len > maxLen) {
			maxLen = len; maxWays = 1;
		} else if (len == maxLen) {
			maxWays++;
		}
	}
	return maxWays;
}

//int main() {
//	char str[10] = "01010";
//	cout << findDifferentWays(5, 3, str) << endl;
//
//	string strstr;
//	cin >> strstr;
//	cout << strstr[0] << " " << strstr[1] <<" " <<  strstr[2] << endl;
//	cout << "size=" << strstr.size() << endl;
//	cout << "capacity=" << strstr.capacity() << endl;
//	string istr = "orig";
//	istr += "ud";
//	cout << istr << endl;
//
//	char a1[] = {'A', 'B', 'C', 'D', 'E'};
//	char a2[] = {'f', 'g', 'h', 'i'};
//	char tmp[100] = {0};
//	cout << "len(a1)=" << strlen(a1) << endl;
//	cout << "len(a2)=" << strlen(a2) << endl;
//	cout << "len(tmp)=" << strlen(tmp) << endl;
//	sprintf(tmp, "%.5s%.4s", a1, a2);
//	cout << "tmp=" << tmp << endl;
//	cout << "len(tmp)=" << strlen(tmp) << endl;
//
//	system("pause");
//	return 0;
//}



void print_vec(vector<int>& v) {
	cout << "-----------------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "empty=" << v.empty() << endl;
	cout << "size=" << v.size() << endl;
	cout << "capacity=" << v.capacity() << endl;
	cout << "max_size=" << v.max_size() << endl;
	cout << "-----------------------------------" << endl;
}

//int main() {
//	int len = 0;
//	cin >> len;
//	vector<int> v;
//	vector<int>::iterator it = v.begin();
//	
//	print_vec(v);
//
//	v.resize(1);
//	//v.reserve(1);
//	print_vec(v);
//
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	
//	
//	it = v.insert(v.begin() + 5, 10);
//	cout << *it << endl;
//
//	*it = 999;
//	
//
//	it = v.erase(v.begin() + 3);
//	cout << *it << endl;
//
//	int d = v.front() + 3;
//	cout << "front + 3 = " << d << endl;
//	
//	v.clear();
//	
//	system("pause");
//	return 0;
//}



bool isFantasyNum(int n) {
	int nums[9] = { 0 };
	int len = 0;
	int sum = 0;
	while (n) {
		nums[len] = n % 10;
		sum += nums[len];
		len++;
		n /= 10;
	}
	if ((sum & 1) != 0)  return false;  // 奇数
	const int halfsum = sum / 2;
	bool flags[41] = { true, };
	for (int i = 0; i < len; i++) {
		for (int j = halfsum; j >= 0; j--) {
			flags[j] = flags[j] || (j >= nums[i]) ? flags[j - nums[i]] : false;  // 上一行正上方，或者上一行左边减去当前数的位置
			if (flags[j] && j == halfsum)  return true;
		}
	}
	return false;
}

//int main() {
//	/*int l, r;
//	cin >> l >> r;
//	if (r == 1000000000)  r--;
//	if (r < l)  return 0;
//	int count = 0;
//	for (int i = l; i <= r; i++) {
//	if (isFantasyNum(i))  count++;
//	}
//	cout << count << endl;*/
//	while (true) {
//	int n;
//	cin >> n;
//	cout << "isFantasyNum=" << isFantasyNum(n) << endl;
//	}
//	return 0;
//}



void split_int(int n, int* arr) {
	for (int i = 0; i < 10; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += arr[j];
		}
	}
}


//int main() {
//	int l, r;
//	cin >> l >> r;
//
//
//	cout << 4 << endl;
//	return 0;
//}



int samelen(char * str, char * dict) {
	int len = 0;
	while (str[len] != 0 && dict[len] != 0 && str[len] == dict[len])  len++;
	return len;
}

//int main() {
//	while (true)
//	{
//		cout << "hello" << endl;
//		char str[100], dict[100];
//		cin >> str >> dict;
//		cout << samelen(str, dict) << endl;
//
//	}
//	//system("pause");
//	getchar();
//	getchar();getchar();
//}



//int main() {
//	long long n;
//	cin >> n;
//	int num = 1;
//	while (n - num > 0) {
//		n -= num;
//		num++;
//	}
//	cout << num << endl;
//	return 0;
//}