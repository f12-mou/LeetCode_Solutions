class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		intervals.push_back(newInterval);
		vector<pair<int, int>> intervals2;
		for (int i = 0; i < intervals.size(); i++)
		{
			intervals2.push_back({intervals[i][0], intervals[i][1]});
			cout << intervals2[i].first << endl;
		}
		sort(intervals2.begin(), intervals2.end());
		vector<vector<int>> ans;
		int leftIdx = intervals2[0].first;
		int rightIdx = intervals2[0].second;
		for (int i = 0; i < intervals2.size(); i++)
		{
			int leftNow = intervals2[i].first;
			int rightNow = intervals2[i].second;
			if (leftNow > rightIdx)
			{
				vector<int> hehe;
				hehe.push_back(leftIdx);
				hehe.push_back(rightIdx);
				ans.push_back(hehe);
				leftIdx = leftNow;
				rightIdx = rightNow;
			}
			else
			{
				leftIdx = min(leftIdx, leftNow);
				rightIdx = max(rightIdx, rightNow);
			}
			if (i == (intervals.size() - 1))
			{
				vector<int> hehe;
				hehe.push_back(leftIdx);
				hehe.push_back(rightIdx);
				ans.push_back(hehe);
			}
		}
		return ans;
	}
};