int preArr[100005];
int suffArr[100005];
int a[100005];
int n;

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		n = height.size();
		for (int i = 1; i <= n; i++)
		{
			a[i] = height[i - 1];
		}
		preArr[1] = a[1];
		for (int i = 2; i <= n; i++)
		{
			preArr[i] = max(preArr[i - 1], a[i]);
		}
		suffArr[n] = a[n];
		for (int i = n - 1; i >= 1; i--)
		{
			suffArr[i] = max(suffArr[i + 1], a[i]);
		}
		int ans = 0LL;
		for (int i = 1; i <= n; i++)
		{
			// amar lefte
			int low = 1, high = i - 1, mid, lefte_koto = -1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if ((preArr[mid]) >= a[i])
				{
					lefte_koto = mid;
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			int koto_1 = 0;
			if (lefte_koto != -1)
			{
				koto_1 = max(koto_1, abs(lefte_koto - i));
			}
			// right side
			low = i + 1;
			high = n;
			int righte_koto = -1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (suffArr[mid] >= a[i])
				{
					righte_koto = mid;
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			int koto_2 = 0;
			if (righte_koto != -1)
			{
				koto_2 = max(koto_2, abs(i - righte_koto));
			}
			ans = max(ans, (koto_1 + koto_2) * a[i]);
		}
		return ans;
	}
};