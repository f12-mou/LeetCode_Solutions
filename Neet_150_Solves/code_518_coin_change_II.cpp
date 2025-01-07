class Solution
{
public:
	int dp[305][5005];
	int a[305];
	int n;
	int func(int pos, int baki)
	{
		if (baki < 0)
			return 0;
		if (baki == 0)
			return 1;
		if (pos >= n)
			return 0;
		if (dp[pos][baki] != -1)
			return dp[pos][baki];
		int ret = 0;
		// nibo
		ret += func(pos, baki - a[pos]);
		// nibo na
		ret += func(pos + 1, baki);
		return dp[pos][baki] = ret;
	}
	int change(int amount, vector<int> &coins)
	{
		n = coins.size();
		for (int i = 0; i < n; i++)
		{
			a[i] = coins[i];
		}
		memset(dp, -1, sizeof(dp));
		int ans = func(0, amount);
		return ans;
	}
};