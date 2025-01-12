class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		stack<pair<int, int>> stck;
		int ans = 0;
		int n = heights.size();
		for (int i = 0; i < n; i++)
		{
			if (stck.empty())
			{
				stck.push({i, heights[i]});
				ans = max(ans, heights[i]);
			}
			else
			{
				int ami_koi = i;
				while (stck.empty() == false && stck.top().second > heights[i])
				{
					ami_koi = stck.top().first;
					int now = stck.top().second;
					stck.pop();
					ans = max(ans, (i - ami_koi) * (now));
				}
				stck.push({ami_koi, heights[i]});
			}
		}

		while (stck.empty() == false)
		{
			int koto = stck.top().second;
			int kothay = stck.top().first;

			cout << "kothay : " << kothay << " koto: " << koto << endl;

			ans = max(ans, (n - 1 - kothay + 1) * koto);
			stck.pop();
		}

		return ans;
	}
};