#include<iostream>
#include<algorithm>

typedef unsigned long long int llu;

using namespace std;

class K 
{
public:
	llu price;
	llu weight;

	K() : price(NULL), weight(NULL)
	{
		
	}
};

int main(void) {
	int k, // k count
		w; // weight
	cin >> k >> w;

	K* ks = new K[k]; // k array
	for (int _k(0); _k < k; _k++)
		cin >> ks[_k].weight >> ks[_k].price;

	llu** dp = new llu * [k + 1];
	dp[0] = new llu[w + 1]{ 0, };
	for (int _k(1); _k < k + 1; _k++) {
		const K& ck = ks[_k - 1]; // current k
		dp[_k] = new llu[w + 1]{ 0, };
		for (int _w(1); _w < w + 1; _w++) {
			if (_w < ck.weight) {
				dp[_k][_w] = dp[_k - 1][_w];
				continue;
			}

			dp[_k][_w] = max(dp[_k - 1][_w - ck.weight] + ck.price, dp[_k - 1][_w]);
		}
	}

	llu max(0);
	for (int _w(1); _w < w + 1; _w++)
		if (dp[k][_w] > max)
			max = dp[k][_w];

	cout << max << endl;

	delete[] ks;
	for (int _k(0); _k < k + 1; _k++)
	{
		delete[] dp[_k];
	}
	delete[] dp;
}