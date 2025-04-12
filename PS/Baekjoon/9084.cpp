#include<iostream>

using namespace std;

int main(void) {
	int tc, //test case count
		cc, //coin count
		cs[20], // coins
		tp; //target price
	cin >> tc;

	for (int _tc(0); _tc < tc; _tc++)
	{
		cin >> cc;
		for (int _cc(0); _cc < cc; _cc++)
			cin >> cs[_cc];
		cin >> tp;

		int dp[20][10000] = { {0, }, };
		for (int _cc(0); _cc < cc; _cc++)
		{
			if (cs[_cc] < tp + 1)
				dp[_cc][cs[_cc] - 1] = 1;
			for (int _tp(cs[_cc]); _tp < tp; _tp++)
			{
				int sum(0);
				for (int i(0); i < _cc + 1; i++)
					sum += dp[i][_tp - cs[_cc]];
				dp[_cc][_tp] = sum;
			}
		}

		int sum(0);
		for (int _cc(0); _cc < cc; _cc++)
			sum += dp[_cc][tp - 1];
		cout << sum << endl;
	}
}

/*
1
3
2 3 5
10
*/