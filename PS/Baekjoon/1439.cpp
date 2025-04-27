#include<iostream>

using namespace std;

string i;
bool l;
int c[2];

int main(void) {
	cin >> i;
	l = i[0] - '0';
	c[l]++;
	for(int _i(1); _i < i.size(); _i++) {
		if(l != i[_i] - '0') c[i[_i] - '0']++;
		l = i[_i] - '0';
	}
	cout << min(c[0], c[1]);
}