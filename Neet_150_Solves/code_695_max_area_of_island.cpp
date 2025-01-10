class Solution
{
public:
	int n, m;
	int ans;
	bool vis[55][55];
	int grid2[55][55];

	int cnt;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	void dfs(int row, int col)
	{
		if (vis[row][col] == true)
			return;
		vis[row][col] = true;
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int next_row = row + dx[i];
			int next_col = col + dy[i];
			if (next_row >= n || next_row < 0)
				continue;
			if (next_col >= m || next_col < 0)
				continue;
			if (vis[next_row][next_col] == true)
				continue;
			if (grid2[next_row][next_col] == 0)
				continue;
			dfs(next_row, next_col);
		}
	}

	int maxAreaOfIsland(vector<vector<int>> &grid)
	{

		n = grid.size();
		m = grid[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				grid2[i][j] = grid[i][j];
			}
		}
		ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vis[i][j] == false && grid2[i][j] == 1)
				{
					cnt = 0;
					dfs(i, j);
					ans = max(ans, cnt);
				}
			}
		}
		return ans;
	}
};