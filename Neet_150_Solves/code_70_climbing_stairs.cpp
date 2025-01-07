int dp[50];
int koita;

int func(int pos)
{
	if (pos == koita)
	{
		return 1;
	}
	if (pos > koita)
	{
		return 0;
	}
	if (dp[pos] != -1)
	{
		return dp[pos];
	}
	int ans = 0;
	ans += func(pos + 1);
	ans += func(pos + 2);
	return dp[pos] = ans;
}

class Solution
{
public:
	int climbStairs(int n)
	{
		koita = n;
		memset(dp, -1, sizeof(dp));
		int now = func(0);
		return now;
	}
};