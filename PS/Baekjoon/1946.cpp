#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class S {
public:
	int s1;
	int s2;
	S(int _s1, int _s2) : s1(_s1), s2(_s2)
	{

	}

	bool operator<(const S &_s) {
		if (this->s1 == _s.s1)
			return this->s2 > _s.s2;
		return this->s1 < _s.s1;
	}
};

int main(void) {
	int t, n, s1, s2;
	cin >> t;
	for (int _t(0); _t < t; _t++)
	{
		int c(1);
		vector<S> ss;
		cin >> n;
		for (int _n(0); _n < n; _n++)
		{
			cin >> s1 >> s2;
			ss.push_back(S(s1, s2));
		}
		sort(ss.begin(), ss.end());
		int ls2(ss[0].s2);
		for (int _n = 1; _n < n; _n++)
		{
			if (ls2 > ss[_n].s2) {
				c++;
				ls2 = ss[_n].s2;
			}
		}
		cout << c << '\n';
	}

}