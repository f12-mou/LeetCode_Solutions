class Solution
{
public:
	vector<string> func(int pos, int sum)
	{
		if (pos <= 0)
		{
			vector<string> hehe;
			hehe.push_back("");
			return hehe;
		}
		if (sum == 0)
		{
			// only ( can be placed
			vector<string> now = func(pos - 1, sum + 1);
			vector<string> ans;
			for (auto itr : now)
			{
				ans.push_back("(" + itr);
			}
			return ans;
		}
		else
		{
			// both ( and ) can be placed
			vector<string> now_1 = func(pos - 1, sum + 1);
			vector<string> now_2 = func(pos - 1, sum - 1);
			vector<string> ans;
			for (auto itr : now_1)
			{
				ans.push_back("(" + itr);
			}
			for (auto itr : now_2)
			{
				ans.push_back(")" + itr);
			}
			return ans;
		}
	}
	vector<string> generateParenthesis(int n)
	{
		vector<string> non_neg = func(n * 2, 0);
		vector<string> ans;
		for (string itr : non_neg)
		{
			int sum = 0;
			for (int i = 0; i < itr.size(); i++)
			{
				if (itr[i] == '(')
				{
					sum++;
				}
				else
				{
					sum--;
				}
			}
			if (sum == 0)
			{
				ans.push_back(itr);
			}
		}
		return ans;
	}
};