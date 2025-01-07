class Solution
{
public:
	bool containsDuplicate(vector<int> &nums)
	{
		bool ok = false;
		map<int, int> mp;
		for (auto itr : nums)
		{
			if (mp[itr] == 0)
			{
				mp[itr] = 1;
			}
			else
			{
				ok = true;
				break;
			}
		}
		return ok;
	}
};