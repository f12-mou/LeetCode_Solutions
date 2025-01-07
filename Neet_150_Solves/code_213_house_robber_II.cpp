#define ll long long
ll a[105];
ll dp[2][109];
int n;

ll func(int ase, int pos)
{
	if (pos > n)
		return 0;
	if (dp[ase][pos] != -1)
		return dp[ase][pos];
	ll ans = 0LL;
	if (pos == 1)
	{
		// nibo
		ans = a[pos] + func(1, (pos + 2));
		// nibo na
		ans = max(ans, func(0, (pos + 1)));
		return dp[ase][pos] = ans;
	}
	if (pos == n)
	{
		if (ase == 0)
		{
			ans = max(ans, a[pos] + func(ase, pos + 2));
		}
		return dp[ase][pos] = ans;
	}
	else
	{
		// nibo
		ans = max(ans, a[pos] + func(ase, pos + 2));
		// nibo na
		ans = max(ans, func(ase, pos + 1));
		return dp[ase][pos] = ans;
	}
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
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j <= 105; j++)
			{
				dp[i][j] = -1;
			}
		}
		int now = func(0, 1);
		return now;
	}
};