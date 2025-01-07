#define ll long long
ll a[2505];
ll dp[2505][2505];
int n;

ll func(int age, int akhon)
{
	if (akhon > n)
	{
		return 0;
	}
	if (dp[age][akhon] != -1)
		return dp[age][akhon];
	// nibo
	ll ans = 0;
	if (a[akhon] > a[age])
	{
		ans = 1 + func(akhon, akhon + 1);
	}
	// nibo na
	ans = max(ans, func(age, akhon + 1));
	return dp[age][akhon] = ans;
}

class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		a[0] = -1e5;
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				dp[i][j] = -1;
			}
		}
		int now = func(0, 1);
		return now;
	}
};