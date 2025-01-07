int preArr[200005];

class Solution
{
public:
	int maxProduct(vector<int> &nums)
	{
		int n = nums.size();
		int ans = -1e9;
		for (int i = 0; i < n; i++)
		{
			int now = 1;
			for (int j = i; j < n; j++)
			{
				now = now * nums[j];
				ans = max(ans, now);
			}
		}
		return ans;
	}
};