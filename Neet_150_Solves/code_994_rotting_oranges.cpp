class Solution
{
public:
	int dist[15][15];
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	bool vis[15][15];
	int orangesRotting(vector<vector<int>> &grid)
	{
		int n, m;
		n = grid.size();
		m = grid[0].size();
		queue<pair<int, int>> q;
		int ans = 0;
		int fresh = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1) // fresh orange
				{
					dist[i][j] = 1e9;
					fresh++;
				}
				else if (grid[i][j] == 2)
				{
					q.push({i, j});
				}
			}
		}
		while (q.empty() == false)
		{
			pair<int, int> p = q.front();
			q.pop();
			int now_row = p.first;
			int now_col = p.second;
			if (vis[now_row][now_col] == true)
				continue;
			vis[now_row][now_col] = true;
			// cout<<"emitted row: "<<now_row+1<<" col: "<<now_col+1<<" dist: "<<dist[now_row][now_col]<<endl;
			if (grid[now_row][now_col] == 1)
			{
				fresh--;
				// cout<<fresh<<" now"<<endl;
			}
			for (int i = 0; i < 4; i++)
			{
				int next_row = now_row + dx[i];
				int next_col = now_col + dy[i];
				// cout<<next_row+1<<" "<<next_col+1<<endl;
				if (next_row < 0)
					continue;
				if (next_row >= n)
					continue;
				if (next_col < 0)
					continue;
				if (next_col >= m)
					continue;
				if (grid[next_row][next_col] == 0)
					continue;
				if (grid[next_row][next_col] == 2)
					continue;
				// fresh orange
				// cout<<"fresh orange: "<<next_row+1<<" "<<next_col+1<<endl;
				if (vis[next_row][next_col] == false)
				{
					dist[next_row][next_col] = min(dist[next_row][next_col], 1 + dist[now_row][now_col]);
					q.push({next_row, next_col});
				}
			}
		}

		// cout<<fresh<<endl;

		if (fresh <= 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (grid[i][j] == 1)
					{
						if (vis[i][j] == false)
						{
							ans = -1;
							break;
						}
						ans = max(ans, dist[i][j]);
					}
				}
				if (ans == -1)
					break;
			}
			return ans;
		}
		else
		{
			return -1;
		}
	}
};