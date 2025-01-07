class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int n = nums.size();
		int max_so_far = -1e9;
		int max_ending_here = 0LL;
		for (int i = 0; i < n; i++)
		{
			max_ending_here += nums[i];
			max_so_far = max(max_so_far, max_ending_here);
			max_ending_here = max(0, max_ending_here);
		}
		return max_so_far;
	}
};