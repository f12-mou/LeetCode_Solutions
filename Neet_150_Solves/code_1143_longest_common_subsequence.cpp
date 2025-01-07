int n1, n2;
int a[1005];
int b[1005];
int dp[1005][1005];

int func(int first, int sec)
{
	if (first > n1)
		return 0;
	if (sec > n2)
		return 0;
	if (dp[first][sec] != -1)
		return dp[first][sec];
	int ans = 0;
	ans = max(ans, func(first + 1, sec));
	ans = max(ans, func(first, sec + 1));
	ans = max(ans, func(first + 1, sec + 1));
	if (a[first] == b[sec])
	{
		ans = max(ans, 1 + func(first + 1, sec + 1));
	}
	return dp[first][sec] = ans;
}

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		n1 = text1.size();
		n2 = text2.size();
		for (int i = 1; i <= n1; i++)
		{
			a[i] = text1[i - 1] - 'a' + 1;
		}
		for (int i = 1; i <= n2; i++)
		{
			b[i] = text2[i - 1] - 'a' + 1;
		}
		for (int i = 0; i <= n1; i++)
		{
			for (int j = 0; j <= n2; j++)
			{
				dp[i][j] = -1;
			}
		}
		int now = func(1, 1);
		return now;
	}
};