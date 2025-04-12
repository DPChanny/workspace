#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class S {
public:
	unsigned int s;
	unsigned int e;

	S(unsigned int _s, unsigned int _e) :
		s(_s), e(_e) {
	}

	bool operator<(const S& _session) {
		if (this->e == _session.e) {
			return this->s < _session.s;
		}
		return this->e < _session.e;
	}
};

int main(void) {
	int n;
	cin >> n;
	vector<S> ss;
	for (int _n(0); _n < n; _n++) {
		unsigned int s, e;
		cin >> s >> e;
		ss.push_back(S(s, e));
	}
	sort(ss.begin(), ss.end());
	unsigned int 
		c(0),
		e(0);
	for (int _n(0); _n < n; _n++) {
		if (e < ss[_n].s + 1) {
			c++;
			e = ss[_n].e;
		}
	}
	cout << c;
}