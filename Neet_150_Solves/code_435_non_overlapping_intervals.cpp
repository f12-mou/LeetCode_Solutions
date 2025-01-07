class Solution
{
public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals)
	{
		vector<pair<int, int>> vec;
		for (int i = 0; i < intervals.size(); i++)
		{
			vec.push_back({intervals[i][0], intervals[i][1]});
		}
		sort(vec.begin(), vec.end());
		int first = vec[0].first;
		int sec = vec[0].second;
		int ans = 0;
		for (int i = 1; i < vec.size(); i++)
		{
			int nowLeft = vec[i].first;
			int nowRight = vec[i].second;
			if (nowLeft >= sec)
			{
				first = nowLeft;
				sec = nowRight;
				continue;
			}
			else
			{
				if (sec < nowRight)
				{
					ans++;
					// ami baad
				}
				else
				{
					ans++;
					first = nowLeft;
					sec = nowRight;
				}
			}
		}
		return ans;
	}
};