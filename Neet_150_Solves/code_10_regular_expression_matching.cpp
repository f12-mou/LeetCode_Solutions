class Solution
{
public:
	int n, m;
	string s2, p2;
	int dp[25][25];

	bool func(int pos_s, int pos_p)
	{
		cout << "in func " << pos_s << " " << pos_p << endl;
		if (pos_s == n)
		{
			if (pos_p != m)
			{
				bool ok = true;
				for (int i = pos_p; i < m; i++)
				{
					if (p2[i] != '*' && p2[i + 1] == '*')
					{
						// good
						i++;
					}
					else
					{
						ok = false;
						break;
					}
				}
				return ok;
			}
			else
			{
				return true;
			}
		}
		if (pos_p == m)
		{
			if (pos_s != n)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		if (dp[pos_s][pos_p] != -1)
		{
			return dp[pos_s][pos_p];
		}
		if ((p2[pos_p + 1] == '*'))
		{
			return dp[pos_s][pos_p] = func(pos_s, pos_p + 1);
		}
		if (p2[pos_p] != '.' && p2[pos_p] != '*')
		{
			// exact match
			if (s2[pos_s] == p2[pos_p])
			{
				dp[pos_s][pos_p] = func(pos_s + 1, pos_p + 1);
			}
			else
			{
				dp[pos_s][pos_p] = false;
			}
		}
		else // . or *
		{
			if (p2[pos_p] == '.')
			{
				// match korano chara way nai
				dp[pos_s][pos_p] = func(pos_s + 1, pos_p + 1);
			}
			else if (p2[pos_p] == '*')
			{
				char prev = p2[pos_p - 1];
				if (prev == '.')
				{
					bool res = false;
					res = res | func(pos_s, pos_p + 1); // zero or more
					int curr = pos_s;
					cout << "here prev: " << prev << endl;
					for (int i = 1; i <= max(n, m); i++)
					{
						int next_s = pos_s + i;

						// int next_p = pos_p +i;
						if (next_s > n)
							break;
						// if(next_p>m) break;
						if (prev == s2[curr] || prev == '.')
						{
							res = res | func(curr + 1, pos_p + 1);
							cout << "matched and curr: " << curr << endl;
							curr++;
						}
						else
						{
							break;
						}
					}
					dp[pos_s][pos_p] = res;
				}
				else
				{
					bool res = false;
					res = res | func(pos_s, pos_p + 1);
					int curr = pos_s;
					cout << "here prev: " << prev << endl;
					for (int i = 1; i <= max(n, m); i++)
					{
						int next_s = pos_s + i;

						// int next_p = pos_p +i;
						if (next_s > n)
							break;
						// if(next_p>m) break;
						if (prev == s2[curr])
						{
							res = res | func(curr + 1, pos_p + 1);
							cout << "matched and curr: " << curr << endl;
							curr++;
						}
						else
						{
							break;
						}
					}
					dp[pos_s][pos_p] = res;
				}
			}
		}
		return dp[pos_s][pos_p];
	}
	bool isMatch(string s, string p)
	{
		n = s.size();
		m = p.size();
		s2 = s;
		p2 = p;
		s2 += "&";
		p2 += "&";
		memset(dp, -1, sizeof(dp));
		bool res = func(0, 0);
		return res;
	}
};