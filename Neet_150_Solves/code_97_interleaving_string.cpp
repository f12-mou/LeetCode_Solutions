class Solution
{
public:
	int n1, n2, n3;
	string t1, t2, t3;

	int dp[102][102][202][2];

	int func(int pos1, int pos2, int pos3, int who)
	{
		if (pos1 == n1 && pos2 == n2 && pos3 == n3)
		{
			return 1;
		}

		if (pos1 == n1 && pos2 == n2)
		{
			return 0;
		}

		if (pos1 == n1 && who == 0)
		{
			return 0;
		}
		if (pos2 == n2 && who == 1)
		{
			return 0;
		}

		if (pos1 == n1 || pos2 == n2)
		{
			string now_hehe = "";
			if (pos1 == n1)
			{
				now_hehe = t2.substr(pos2, n2 - 1 - pos2 + 1);
			}
			else
			{
				now_hehe = t1.substr(pos1, n1 - 1 - pos1 + 1);
			}
			string now = t3.substr(pos3, n3 - 1 - pos3 + 1);
			if (now == now_hehe)
				return 1;
			else
				return 0;
		}

		if (dp[pos1][pos2][pos3][who] != -1)
		{
			return dp[pos1][pos2][pos3][who];
		}

		if (who == 0)
		{
			if (t1[pos1] == t3[pos3])
			{
				return dp[pos1][pos2][pos3][who] = func(pos1 + 1, pos2, pos3 + 1, 1) | func(pos1 + 1, pos2, pos3 + 1, 0);
			}
			else
			{
				return dp[pos1][pos2][pos3][who] = 0;
			}
		}
		if (who == 1)
		{
			if (t2[pos2] == t3[pos3])
			{
				return dp[pos1][pos2][pos3][who] = func(pos1, pos2 + 1, pos3 + 1, 1) | func(pos1, pos2 + 1, pos3 + 1, 0);
			}
			else
			{
				return dp[pos1][pos2][pos3][who] = 0;
			}
		}
		return dp[pos1][pos2][pos3][who];
	}

	bool isInterleave(string s1, string s2, string s3)
	{
		t1 = s1;
		t2 = s2;
		t3 = s3;

		n1 = s1.size();
		n2 = s2.size();
		n3 = s3.size();

		memset(dp, -1, sizeof(dp));

		int ans = func(0, 0, 0, 0) | func(0, 0, 0, 1);

		if (ans == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};