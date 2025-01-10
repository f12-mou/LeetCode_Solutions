class Solution
{
public:
	int bias = 105;
	int dp[102][505];
	string s2;

	int n;

	int func(int pos, int now)
	{
		cout << pos << " " << now << endl;
		if (now < bias)
			return 0;
		if (pos >= n)
		{
			if (now == bias)
				return 1;
			else
				return 0;
		}
		if (dp[pos][now] != -1)
			return dp[pos][now];

		if (s2[pos] == '(')
		{
			return dp[pos][now] = func(pos + 1, now + 1);
		}
		else if (s2[pos] == ')')
		{
			return dp[pos][now] = func(pos + 1, now - 1);
		}
		else
		{
			int way_1 = func(pos + 1, now + 1);
			int way_2 = func(pos + 1, now - 1);
			int way_3 = func(pos + 1, now);
			return dp[pos][now] = way_1 | way_2 | way_3;
		}
		return 0;
	}

	bool checkValidString(string s)
	{
		n = s.size();
		s2 = s;
		memset(dp, -1, sizeof(dp));
		int ans = func(0, bias);
		if (ans == 1)
			return true;
		else
			return false;
	}
};