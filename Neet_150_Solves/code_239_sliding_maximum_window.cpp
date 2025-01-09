class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		int n = nums.size();
		map<int, int> cnt;
		map<int, int> present;
		priority_queue<int> pq;
		vector<int> ans;

		for (int i = 0; i < k; i++)
		{
			cnt[nums[i]]++;
			if (present[nums[i]] == 0)
			{
				present[nums[i]] = 1;
				pq.push(nums[i]);
			}
		}
		ans.push_back(pq.top());
		for (int i = k; i < n; i++)
		{
			int ager_elem = nums[i - k];
			int akhon_elem = nums[i];
			cnt[ager_elem]--;
			cnt[akhon_elem]++;
			if (present[akhon_elem] == 0)
			{
				present[akhon_elem] = 1;
				pq.push(akhon_elem);
			}
			int maxi_now = 0;
			while (pq.empty() == false)
			{
				maxi_now = pq.top();
				if (cnt[maxi_now] == 0)
				{
					present[maxi_now] = 0;
					pq.pop();
				}
				else
				{
					ans.push_back(maxi_now);
					break;
				}
			}
		}
		return ans;
	}
};