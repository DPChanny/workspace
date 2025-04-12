#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	for(size_t _t(0); _t < t; _t++) {
		string tmp;
		cin >> tmp;

		stack<int> dummy;

		bool flag(false);

		for(size_t _i(0); _i < tmp.length(); _i++) {
			if(tmp[_i] == '(') {
				dummy.push(1);
			} else {
				if(dummy.empty()) {
					cout << "NO" << endl;
					flag = true;
					break;
				}
				dummy.pop();
			}
		}

		if(!flag) {
			cout << (!dummy.size() ? "YES" : "NO") << endl;
		}
	}
}