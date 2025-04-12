#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

struct P {
	int start;
	int end;
};

string input;
vector<P> ps;
vector<string> results;
int use[200];

void r(int _n) {
	if (_n == ps.size()) {
		string result;
		bool flag(false);
		for (int i(0); i < input.length(); i++) {
			if (!use[i]) result += input[i];
			if (!flag) flag = use[i];
		}
		if (flag) results.push_back(result);
		return;
	}
	use[ps[_n].start] = 0;
	use[ps[_n].end] = 0;
	r(_n + 1);
	use[ps[_n].start] = 1;
	use[ps[_n].end] = 1;
	r(_n + 1);
}

int main(void) {
	stack<int> stack;
	cin >> input;
	for (int i(0); i < input.length(); i++)
	{
		if (input[i] == '(') stack.push(i);
		else if (input[i] == ')') {
			ps.push_back({ stack.top(), i });
			stack.pop();
		}
	}
	r(0);
	sort(results.begin(), results.end());
	results.erase(unique(results.begin(), results.end()), results.end());
	for (int i(0); i < results.size(); i++)
		cout << results[i] << '\n';
}