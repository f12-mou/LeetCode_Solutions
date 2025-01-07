int n;
int a[5005];

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = nums[i - 1];
		}
		int low = 1, high = n, mid, ans = -1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] == target)
			{
				ans = mid;
			}
			if ((a[high] <= a[low]) && (a[low] <= a[mid])) // we are on upper side
			{
				if ((a[low] <= target) && (target <= a[mid])) // we are on this
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			else // we are on lower hand
			{
				if ((a[mid] <= target) && (target <= a[high]))
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
		}
		ans--;
		if (ans < 0)
			return -1;
		else
			return ans;
	}
};