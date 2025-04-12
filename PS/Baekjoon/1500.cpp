#include<iostream>
#include<cmath>

using namespace std;

unsigned long long int s, k, q, r;

int main(void) {
	cin >> s >> k;
	q = s / k;
	r = s % k;
	cout << (unsigned long long int)(pow(q, k - r) * pow(q + 1, r));
}