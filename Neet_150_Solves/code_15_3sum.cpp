int a[30005];

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		int n = nums.size();
		map<int, int> cnt;
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
			cnt[a[i]]++;
		}
		int start = 0;
		nums.clear();
		for (auto itr : cnt)
		{
			int mini = min(2, itr.second);
			for (int i = 1; i <= mini; i++)
			{
				nums.push_back(itr.first);
			}
		}
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		map<int, int> mp;
		vector<vector<int>> ans;
		// set<vector<int>>ana;
		mp[a[1]] = 1;
		map<int, bool> hehe;
		set<vector<int>> ana;
		for (int i = 2; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				vector<int> hehe;
				int now = a[i] + a[j];
				if (mp[-now] != 0)
				{
					hehe.push_back(a[mp[-now]]);
					hehe.push_back(a[i]);
					hehe.push_back(a[j]);
					sort(hehe.begin(), hehe.end());
					ana.insert(hehe);
				}
			}
			mp[a[i]] = i;
		}
		if (cnt[0] >= 3)
		{
			ana.insert({0, 0, 0});
		}
		for (auto itr : ana)
		{
			ans.push_back(itr);
		}
		return ans;
	}
};