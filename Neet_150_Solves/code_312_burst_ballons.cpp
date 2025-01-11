class Solution
{
public:
	int a[305];
	int n;
	int dp[305][305];

	int func(int l, int r)
	{
		if (l > r)
			return 0;
		if (dp[l][r] != -1)
			return dp[l][r];

		int ans = 0;
		for (int i = l; i <= r; i++)
		{
			// i shobar last e jabe
			ans = max(ans, func(l, i - 1) + func(i + 1, r) + a[i] * a[l - 1] * a[r + 1]);
		}
		return dp[l][r] = ans;
	}

	int maxCoins(vector<int> &nums)
	{
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		a[0] = a[n + 1] = 1;
		memset(dp, -1, sizeof(dp));
		return func(1, n);
	}
};