int preArr[200005];

class Solution
{
public:
	bool canJump(vector<int> &nums)
	{
		int n = nums.size();
		for (int i = 0; i <= n; i++)
		{
			preArr[i] = 0;
		}
		preArr[1] = 1;
		preArr[1 + nums[0] + 1] = -1;
		for (int i = 1; i <= n; i++)
		{
			preArr[i] += preArr[i - 1];
			if (preArr[i] <= 0)
				continue;
			preArr[i] += 1;
			preArr[i + nums[i - 1] + 1] += (-1);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << preArr[i] << endl;
		}
		if (preArr[n] > 0)
			return true;
		else
			return false;
	}
};