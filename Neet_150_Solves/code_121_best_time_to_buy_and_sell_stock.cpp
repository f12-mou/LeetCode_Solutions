#include <bits/stdc++.h>
using namespace std;
int n;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		n = prices.size();
		if (n == 1)
		{
			return 0;
		}
		int maxi = 0LL;
		int so_far = prices[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			maxi = max(maxi, so_far - prices[i]);
			so_far = max(so_far, prices[i]);
		}
		return maxi;
	}
};