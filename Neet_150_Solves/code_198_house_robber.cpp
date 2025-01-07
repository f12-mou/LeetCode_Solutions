#define ll long long
int n;
ll a[106];
ll dp[105];

ll func(int pos)
{
	if (pos > n)
		return 0LL;
	if (dp[pos] != -1)
		return dp[pos];
	// nibo
	ll ans = a[pos] + func(pos + 2);
	ans = max(ans, func(pos + 1));
	return dp[pos] = ans;
}

class Solution
{
public:
	int rob(vector<int> &nums)
	{
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		for (int i = 0; i <= n; i++)
		{
			dp[i] = -1;
		}
		int now = func(1);
		return now;
	}
};