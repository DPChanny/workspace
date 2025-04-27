#include<iostream>
#include<queue>

using namespace std;

constexpr int MAX = 100001;

int n, k,
cp, // current position
ct, // current time
ft, // fastest time
vs[MAX]; // visited status
bool flag;

int main(void) {
	for (int _vs(0); _vs < MAX; _vs++)
		vs[_vs] = 2147483647;
	ft = 2147483647;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	cin >> n >> k;
	q.emplace(0, n); // �Ű����� ���� ����
	while (true) {
		cp = q.top().second; // �Ű����� ���� ����
		ct = q.top().first;  // �Ű����� ���� ����
		q.pop();
		if (cp == k) {
			cout << ct;
			break;
		}
		if (cp * 2 < MAX && ct < vs[cp * 2]) {
			q.emplace(ct, cp * 2); // �Ű����� ���� ����
			vs[cp * 2] = ct;
		}
		if (cp + 1 < MAX && ct < vs[cp + 1]) {
			q.emplace(ct + 1, cp + 1); // �Ű����� ���� ����
			vs[cp + 1] = ct;
		}
		if (cp - 1 >= 0 && ct < vs[cp - 1]) {
			q.emplace(ct + 1, cp - 1); // �Ű����� ���� ����
			vs[cp - 1] = ct;
		}
	}
}