#include<queue>
#include<iostream>

using namespace std;

int n, m, bn;
uint64_t ba, bb, s;

int main(void) {
	priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> q;
	cin >> n >> m;
	for(int _n(0); _n < n; _n++) {
		cin >> bn;
		q.push(bn);
	}
	for(int _m(0); _m < m; _m++) {
		ba = q.top(); q.pop();
		bb = q.top(); q.pop();
		q.push(ba + bb); q.push(ba + bb);
	}
	for(int _n(0); _n < n; _n++) {
		s += q.top(); q.pop();
	}
	cout << s;
}