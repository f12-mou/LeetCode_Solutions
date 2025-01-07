class Solution
{
public:
	map<int, char> mp;
	int n;
	string digits2;

	vector<string> func(int pos)
	{
		if (pos >= n)
		{
			vector<string> hehe;
			hehe.push_back("");
			return hehe;
		}
		vector<string> now;
		int dig = digits2[pos] - '0';
		for (int i = 0; i < 3; i++)
		{
			char who = mp[dig] + i;
			vector<string> now2 = func(pos + 1);
			for (auto itr : now2)
			{
				string f = who + itr;
				now.push_back(f);
			}
		}
		if (dig == 7 || dig == 9)
		{
			char who = mp[dig] + 3;
			vector<string> now2 = func(pos + 1);
			for (auto itr : now2)
			{
				string f = who + itr;
				now.push_back(f);
			}
		}
		return now;
	}

	vector<string> letterCombinations(string digits)
	{
		mp[2] = 'a';
		mp[3] = 'd';
		mp[4] = 'g';
		mp[5] = 'j';
		mp[6] = 'm';
		mp[7] = 'p';
		mp[8] = 't';
		mp[9] = 'w';

		if (digits.empty() == true)
		{
			vector<string> ans;
			ans.clear();
			return ans;
		}

		digits2 = digits;
		n = digits.size();
		vector<string> ans = func(0);
		return ans;
	}
};