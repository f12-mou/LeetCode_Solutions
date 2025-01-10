class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		int ans1, ans2;
		int n = numbers.size();
		for (int i = 1; i <= n; i++)
		{
			int now = numbers[i - 1];
			int baki = target - now;
			ans1 = i;

			int low, high, mid, ans = -1;
			if (baki == now)
			{
				int cand_1 = i + 1;
				if ((cand_1 <= n) && numbers[cand_1 - 1] == baki)
				{
					ans2 = cand_1;
					break;
				}
				cand_1 = i - 1;
				if ((cand_1 >= 1) && numbers[cand_1 - 1] == baki)
				{
					ans2 = cand_1;
					break;
				}
				// nai
			}
			else
			{
				if (baki < now)
				{
					low = 1;
					high = i - 1;
				}
				else
				{
					low = i + 1;
					high = n;
				}
				while (low <= high)
				{
					mid = (low + high) / 2;
					if (numbers[mid - 1] == baki)
					{
						ans = mid;
						break;
					}
					else if (numbers[mid - 1] < baki)
					{
						low = mid + 1;
					}
					else
					{
						high = mid - 1;
					}
				}
				if (ans == -1)
				{
					continue;
				}
				else
				{
					ans2 = ans;
					break;
				}
			}
		}
		vector<int> hehe;
		hehe.push_back(ans1);
		hehe.push_back(ans2);
		return hehe;
	}
};