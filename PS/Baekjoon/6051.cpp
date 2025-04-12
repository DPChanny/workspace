#include<iostream>

using namespace std;

struct Q {
	Q* pq;
	char q;
	int k;
};

int n;
Q** qs;

int glk(int _n) {
	Q* q = qs[_n];
	int s(0);
	while(true) {
		if(q->q == 'a') {
			if(s) s--;
			else return q->k;
		} else if(q->q == 's') s++;
		q = q->pq;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	qs = new Q * [n + 1]{ new Q{ nullptr, 'a', -1 } , };
	for(int _n(1); _n < n + 1; _n++) {
		qs[_n] = new Q;
		cin >> qs[_n]->q; 
		if(qs[_n]->q == 's') qs[_n]->pq = qs[_n - 1];
		else {
			cin >> qs[_n]->k;
			if(qs[_n]->q == 't') qs[_n]->pq = qs[qs[_n]->k - 1];
			else qs[_n]->pq = qs[_n - 1];
		}
		cout << glk(_n) << '\n';
	}
	for(int _n(0); _n < n; _n++)
		delete qs[_n];
	delete[] qs;
}