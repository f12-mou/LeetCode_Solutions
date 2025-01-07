class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		vector<pair<int, int>> vec;
		for (auto itr : intervals)
		{
			vec.push_back({itr[0], itr[1]});
		}
		sort(vec.begin(), vec.end());
		vector<vector<int>> ans;
		int start = vec[0].first;
		int endIdx = vec[0].second;
		for (int i = 1; i < vec.size(); i++)
		{
			int now_start = vec[i].first;
			int now_endIdx = vec[i].second;
			if (now_start > endIdx)
			{
				vector<int> hehe;
				hehe.push_back(start);
				hehe.push_back(endIdx);
				ans.push_back(hehe);
				start = now_start;
				endIdx = now_endIdx;
			}
			else
			{
				endIdx = max(endIdx, now_endIdx);
			}
		}
		vector<int> hehe;
		hehe.push_back(start);
		hehe.push_back(endIdx);
		ans.push_back(hehe);
		return ans;
	}
};