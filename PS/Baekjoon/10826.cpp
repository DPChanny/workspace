#include<iostream>
#include<string>

using namespace std;

string Add(string& _a, string& _b);

int main(void) {
	string f1 = "0";
	string f2 = "1";
	int n = 0;

	cin >> n;

	string temp;
	for (int i = 0; i < n - 1; i++)
	{
		temp = f1;
		f1 = f2;
		f2 =Add(temp, f1);
	}

	if (n == 0) {
		cout << f1 << endl;
	}
	else {
		cout << f2 << endl;
	}
}
string Add(string& s1, string& s2) { 
	string result(max(s1.size(), s2.size()), '0');
	bool carry = false; 
	for (int i = 0; i < result.size(); i++) {
		int temp = carry; carry = false;
		if (i < s1.size()) temp += s1[s1.size() - i - 1] - '0';
		if (i < s2.size()) temp += s2[s2.size() - i - 1] - '0'; 
		if (temp >= 10) { 
			carry = true;
			temp -= 10; 
		} 
		result[result.size() - i - 1] = temp + '0'; 
	} 
	if (carry) result.insert(result.begin(), '1'); 
	return result;
}
