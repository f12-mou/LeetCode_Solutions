class Solution
{
public:
	int n, m;
	string s, t;
	int dp[505][505];

	int func(int pos1, int pos2) // n ...... m
	{
		if (pos1 > n)
		{
			if (pos2 > m)
				return 0;
			else
				return m - pos2 + 1;
		}
		if (pos2 > m)
		{
			if (pos1 > n)
				return 0;
			else
			{
				return (n - pos1 + 1);
			}
		}
		if (dp[pos1][pos2] != -1)
			return dp[pos1][pos2];
		int ans = 1e9;
		if (s[pos1] == t[pos2])
		{
			ans = func(pos1 + 1, pos2 + 1);
			// match korabo na
			// delete korbo
			ans = min(ans, 1 + func(pos1, pos2 + 1));
			// insert korbo
			ans = min(ans, 1 + func(pos1 + 1, pos2));
			// replace korar mane nai
		}
		else
		{
			ans = 1 + func(pos1 + 1, pos2 + 1);
			// match korabo na
			// delete korbo
			ans = min(ans, 1 + func(pos1, pos2 + 1));
			// insert korbo
			ans = min(ans, 1 + func(pos1 + 1, pos2));
			// replace korar mane nai
		}
		return dp[pos1][pos2] = ans;
	}

	int minDistance(string word1, string word2)
	{
		s = word2;
		t = word1;

		n = s.size();
		m = t.size();

		s = " " + s;
		t = " " + t;

		memset(dp, -1, sizeof(dp));

		int ans = func(1, 1);
		return ans;
	}
};