class Solution
{
public:
	int a[200005];
	int n;
	int dp[200005];

	int func(int pos)
	{
		if (pos >= n)
		{
			return 0;
		}
		if (a[pos] == 0)
		{
			return 1e5;
		}
		if (dp[pos] != -1)
			return dp[pos];
		int ans = 1e5;
		for (int i = 1; i <= a[pos]; i++)
		{
			ans = min(ans, 1 + func(pos + i));
		}
		return dp[pos] = ans;
	}

	int jump(vector<int> &nums)
	{
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		memset(dp, -1, sizeof(dp));
		int ans = func(1);
		return ans;
	}
};