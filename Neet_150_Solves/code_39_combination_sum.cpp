class Solution
{
public:
	int n;
	int a[35];

	vector<vector<int>> func(int pos, int baki)
	{
		// koto bar nibo
		if (pos > n)
		{
			if (baki != 0)
			{
				vector<vector<int>> ans;
				vector<int> vec;
				vec.push_back(-1);
				ans.push_back(vec);
				return ans;
			}
			else
			{
				vector<vector<int>> ans;
				vector<int> vec;
				ans.push_back(vec);
				return ans;
			}
		}
		if (baki < 0)
		{
			vector<vector<int>> ans;
			vector<int> vec;
			vec.push_back(-1);
			ans.push_back(vec);
			return ans;
		}
		if (baki == 0)
		{
			vector<vector<int>> ans;
			vector<int> vec;
			ans.push_back(vec);
			return ans;
		}

		int now = a[pos];

		vector<vector<int>> ans;

		for (int i = 0; i <= baki; i++)
		{
			int koto = i * now;
			if (koto > baki)
				break;
			cout << i << endl;

			vector<vector<int>> bl = func(pos + 1, baki - koto);
			if (bl.empty() == true)
				continue;
			if (bl[0].empty() == true)
			{
				vector<int> hehe;
				for (int j = 1; j <= i; j++)
				{
					hehe.push_back(now);
				}
				if (i != 0)
				{
					ans.push_back(hehe);
				}
				continue;
			}

			// else it is valid
			for (auto itr : bl)
			{
				if (itr.empty() == true)
				{
					for (int j = 1; j <= i; j++)
					{
						itr.push_back(now);
					}
					if (i != 0)
					{
						ans.push_back(itr);
					}
				}
				if (itr[0] == -1)
					continue;
				for (int j = 1; j <= i; j++)
				{
					itr.push_back(now);
				}
				ans.push_back(itr);
			}
		}
		if (ans.empty())
		{
			vector<int> vec;
			vec.push_back(-1);
			ans.push_back(vec);
		}
		return ans;
	}

	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		n = candidates.size();
		for (int i = 0; i < n; i++)
		{
			a[i + 1] = candidates[i];
		}

		vector<vector<int>> vec = func(1, target);
		if (vec[0][0] == -1)
		{
			vec.clear();
			return vec;
		}
		return vec;
	}
};