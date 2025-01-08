class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<pair<string, int>> vec;
		int n = strs.size();
		for (int i = 0; i < n; i++)
		{
			string now = strs[i];
			sort(now.begin(), now.end());
			vec.push_back({now, i});
		}
		sort(vec.begin(), vec.end());
		vector<vector<string>> ans;
		vector<vector<int>> temp;
		vector<int> hehe;

		for (auto itr : vec)
		{
			cout << itr.first << " " << itr.second << endl;
		}

		for (int i = 0; i < n; i++)
		{
			string now = strs[vec[i].second];
			int idx = vec[i].second;
			sort(now.begin(), now.end());
			if (i == 0)
			{
				hehe.push_back(idx);
			}
			else
			{
				int lastS = hehe[hehe.size() - 1];
				// cout<<"index: "<<i+1<<" "<<lastS<<" now: "<<now<<endl;
				string now2 = strs[lastS];
				sort(now2.begin(), now2.end());
				if (now2 != now)
				{
					cout << "not eq " << " lastS: " << lastS << " now: " << now << " arekta: " << vec[lastS].first << endl;
					temp.push_back(hehe);
					hehe.clear();
					hehe.push_back(idx);
				}
				else
				{
					hehe.push_back(idx);
				}
			}
			if (i == n - 1)
			{
				if (hehe.empty() == false)
				{
					temp.push_back(hehe);
					hehe.clear();
				}
			}
		}
		for (auto itr : temp)
		{
			vector<string> now;
			for (auto itr2 : itr)
			{
				now.push_back(strs[itr2]);
			}
			ans.push_back(now);
		}

		return ans;
	}
};