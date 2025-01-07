int preArr[100005];
int suffArr[100005];
int n;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
		n = nums.size();
		preArr[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			preArr[i] = preArr[i - 1] * nums[i];
		}
		suffArr[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			suffArr[i] = suffArr[i + 1] * (nums[i]);
		}
		vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				ans[i] = suffArr[1];
			}
			else if (i == n - 1)
			{
				ans[i] = preArr[n - 2];
			}
			else
			{
				ans[i] = preArr[i - 1] * suffArr[i + 1];
			}
		}
		return ans;
	}
};