#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct L {
	uint32_t s, e;

	bool operator<(const L& _l) const {
		return s > _l.s;
	}
};

uint32_t n, bs, be;
priority_queue<L> q;
priority_queue<
	uint32_t,
	vector<uint32_t>,
	greater<uint32_t>> es;

int main(void) {
	cin >> n;
	for(uint32_t _n(0); _n < n; _n++) {
		cin >> bs >> be;
		q.push({ bs, be });
	}
	L cq;
	es.push(0);
	while(!q.empty()) {
		cq = q.top(); q.pop();
		if(es.top() < cq.s + 1) {
			es.pop(); es.push(cq.e);
		}
		else es.push(cq.e);
	}
	cout << es.size();
}
