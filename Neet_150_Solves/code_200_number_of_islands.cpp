class Solution
{
public:
	int n, m;

	vector<vector<char>> a;

	int cnt;

	bool vis[305][305];

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	void dfs(int row, int col)
	{
		if (vis[row][col] == true)
			return;
		vis[row][col] = true;

		for (int i = 0; i < 4; i++)
		{
			int next_row = row + dx[i];
			int next_col = col + dy[i];
			if (next_row < 0)
				continue;
			if (next_col < 0)
				continue;
			if (next_row >= n)
				continue;
			if (next_col >= m)
				continue;

			if (a[next_row][next_col] == '0')
				continue;
			if (vis[next_row][next_col])
				continue;
			dfs(next_row, next_col);
		}
	}

	int numIslands(vector<vector<char>> &grid)
	{
		n = grid.size();
		m = grid[0].size();

		a = grid;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vis[i][j] == false && a[i][j] == '1')
				{
					cnt++;
					dfs(i, j);
				}
			}
		}

		return cnt;
	}
};