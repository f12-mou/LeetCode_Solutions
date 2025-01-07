class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int n = nums.size();
		map<int, int> mp1, mp2; // same indices can't be added up, hence two maps
		// think about 5,5,2,3,17   target = 10
		for (int i = 0; i < n; i++)
		{
			mp1[nums[i]] = i; // tracking the first instance
		}
		for (int i = n - 1; i >= 0; i--)
		{
			mp2[nums[i]] = i; // tracking the last instance
		}
		int idx1, idx2, ok = 0;
		for (int i = 0; i < n; i++)
		{
			int now = nums[i];
			int baki = target - now;
			idx1 = i; // see what happens if we take it
			if (mp1.count(baki) != 0)
			{
				if (mp1[baki] != idx1)
				{
					idx2 = mp1[baki];
					break;
				}
			}
			if (mp2.count(baki) != 0)
			{
				if (mp2[baki] != idx1)
				{
					idx2 = mp2[baki];
					break;
				}
			}
		}
		vector<int> ans;
		ans.push_back(idx1);
		ans.push_back(idx2);
		return ans;
	}
};