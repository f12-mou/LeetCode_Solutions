class Solution
{
public:
	int arr[200005];
	int preArr[200005];
	int n;
	int trap(vector<int> &height)
	{
		n = height.size();
		int maxiIdx = 1;
		int maxi = 0;
		for (int i = 1; i <= n; i++)
		{
			arr[i] = height[i - 1];
			if (maxi == arr[i])
			{
				maxiIdx = i;
			}
			else if (arr[i] > maxi)
			{
				maxi = arr[i];
				maxiIdx = i;
			}
		}
		cout << maxiIdx << endl;
		preArr[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			preArr[i] = (preArr[i - 1] + arr[i]);
		}

		int finalAns = 0;
		stack<int> stck;
		stck.push(1);
		for (int i = 2; i <= maxiIdx; i++)
		{
			int now = stck.top();
			int nowVal = arr[now];
			if (nowVal <= arr[i])
			{
				cout << "inside 1st block" << endl;
				int hehe = max(0, i - 1 - now) * nowVal;
				cout << "init hehe: " << hehe << endl;
				hehe -= max(0, (preArr[i - 1] - preArr[now]));
				hehe = max(hehe, 0);

				cout << "index: " << i << " inner len: " << (i - 1 - now) << " hehe is: " << hehe << endl;

				finalAns += hehe;
				stck.push(i);
			}
		}

		while (stck.empty() == false)
		{
			stck.pop();
		}
		stck.push(n);
		for (int i = n - 1; i >= maxiIdx; i--)
		{
			int now = stck.top();
			int nowVal = arr[now];
			if (nowVal <= arr[i])
			{
				int hehe = max(0, now - i - 1) * nowVal;
				hehe -= (preArr[now - 1] - preArr[i]);
				hehe = max(hehe, 0);
				finalAns += hehe;
				stck.push(i);
			}
		}
		return finalAns;
	}
};