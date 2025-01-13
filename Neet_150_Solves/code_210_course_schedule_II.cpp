class Solution
{
public:
	bool vis[20005];
	vector<int> ans;
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
	{
		int n = numCourses;

		map<int, int> mp;
		map<int, vector<int>> hehe;

		for (int i = 0; i < prerequisites.size(); i++)
		{
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			mp[b]++;
			hehe[a].push_back(b);
			cout << "b: " << b << " is pushed into : " << a << endl;
		}
		queue<int> q;

		for (int i = 0; i < n; i++)
		{
			if (mp[i] == 0)
			{
				q.push(i);
			}
		}
		while (q.empty() == false)
		{
			int now = q.front();
			q.pop();
			ans.push_back(now);
			vis[now] = true;

			for (int i = 0; i < hehe[now].size(); i++)
			{
				int who = hehe[now][i];
				mp[who]--;
				cout << "now who: " << now << " " << who << endl;
				if (mp[who] == 0)
				{
					q.push(who);
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == false)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			reverse(ans.begin(), ans.end());
			return ans;
		}
		else
		{
			ans.clear();
			return ans;
		}
	}
};
