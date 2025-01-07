
int a[5005];
int n;

class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		n = nums.size();
		for (int i = 0; i < n; i++)
		{
			a[i + 1] = nums[i];
		}
		int low = 1, high = n, mid, ans = 1e9;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if ((a[mid] >= a[low]) && (a[low] >= a[high]))
			{
				ans = min(ans, a[mid]);
				low = mid + 1;
			}
			else
			{
				ans = min(ans, a[mid]);
				high = mid - 1;
			}
		}
		return ans;
	}
};