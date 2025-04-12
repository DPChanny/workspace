#include<iostream>
#include<vector>

using namespace std;

int n, s, d, bf, bt, c;
vector<int> ns[100'000];
bool vs[100'000];

int gc(int _f) {
	int md(0);
	vs[_f] = true;
	for(int _t(0); _t < ns[_f].size(); _t++)
		if(!vs[ns[_f][_t]])
			md = max(md, gc(ns[_f][_t]));
	if(md + 1 > d) c++;
	return md + 1;
}

int main(void) {
	cin >> n >> s >> d;
	for(int _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		ns[bf - 1].push_back(bt - 1);
		ns[bt - 1].push_back(bf - 1);
	}
	gc(s - 1);
	cout << max(0, (c - 1)) * 2;
}
