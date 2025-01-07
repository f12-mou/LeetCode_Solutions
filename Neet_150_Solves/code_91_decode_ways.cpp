int n;
char a[105];
int dp[505];
bool ok;

int func(int pos)
{
	if (pos > n)
		return 1;
	if (dp[pos] != -1)
		return dp[pos];
	if (a[pos] == '0')
	{
		return 0;
	}
	int ans = 0;
	if ((pos + 1 <= n))
	{
		if (a[pos + 1] != '0')
			ans = func(pos + 1);
		else
		{
			if (a[pos] >= '3')
			{
				return 0;
			}
			else
			{
			}
		}
	}
	else

	{
		ans += func(pos + 1);
	}

	// duitai nibo
	if ((pos + 1) <= n)
	{
		if (a[pos] == '1')
		{
			ans = ans + func(pos + 2);
		}
		else if (a[pos] == '2')
		{
			if (a[pos + 1] <= '6')
			{
				ans = ans + func(pos + 2);
			}
		}
	}
	return dp[pos] = ans;
}

class Solution
{
public:
	int numDecodings(string s)
	{
		n = s.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = s[i - 1];
		}
		for (int i = 0; i <= n; i++)
		{
			dp[i] = -1;
		}
		ok = true;
		if (s[0] == '0')
			return 0;
		int now = func(1);
		return now;
	}
};