class Solution
{
public:
	int arr[100005];
	int n;
	int preArr[100005];
	int preMin[100005];
	int suffMin[100005];

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		n = cost.size();
		for (int i = 1; i <= n; i++)
		{
			arr[i] = gas[i - 1] - cost[i - 1];
		}
		preArr[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			preArr[i] = preArr[i - 1] + arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				preMin[i] = preArr[i];
			}
			else
			{
				preMin[i] = min(preMin[i - 1], preArr[i]);
			}
		}
		for (int i = n; i >= 1; i--)
		{
			if (i == n)
			{
				suffMin[i] = preArr[i];
			}
			else
			{
				suffMin[i] = min(suffMin[i + 1], preArr[i]);
			}
		}

		int idx = -1;

		for (int i = 1; i <= n; i++)
		{
			int shamner_min = suffMin[i];
			shamner_min = shamner_min - preArr[i - 1];

			int picher_min = preMin[i - 1];
			picher_min += (preArr[n] - preArr[i - 1]);

			cout << "idx: " << i << " shamner min: " << shamner_min << " picher min " << picher_min << endl;

			int final_min = min(shamner_min, picher_min);
			if (final_min >= 0)
			{
				idx = i;
				break;
			}
		}
		if (idx == -1)
			return idx;
		idx--;
		return idx;
	}
};