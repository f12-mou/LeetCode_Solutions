class Solution
{
public:
	int lastStoneWeight(vector<int> &stones)
	{

		priority_queue<int> pq;
		int n = stones.size();
		if (n == 1)
		{
			return stones[0];
		}
		for (int i = 0; i < n; i++)
		{
			pq.push(stones[i]);
		}
		while (pq.size() != 1)
		{
			int boro = pq.top();
			pq.pop();
			int choto = pq.top();
			pq.pop();
			pq.push(boro - choto);
		}
		int ans = 0;
		while (pq.empty() == false)
		{
			ans = pq.top();
			pq.pop();
		}
		return ans;
	}
};