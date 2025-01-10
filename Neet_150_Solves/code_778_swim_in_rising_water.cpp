class Solution
{
public:
	int n, m;
	int a[55][55];
	int vis[55][55];

	int target_vis;
	int allowed;

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	void dfs(int row, int col)
	{
		if (vis[row][col] == target_vis)
			return;
		vis[row][col] = target_vis;

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dx[i];
			int ncol = col + dy[i];

			if (nrow < 1 || nrow > n)
				continue;
			if (ncol < 1 || ncol > m)
				continue;
			if (vis[nrow][ncol] == target_vis)
				continue;
			if (a[nrow][ncol] > allowed)
				continue;

			dfs(nrow, ncol);
		}
	}

	bool func(int allowed_maximum)
	{
		allowed = allowed_maximum;
		target_vis++;
		if (a[1][1] > allowed_maximum)
		{
			return false;
		}
		dfs(1, 1);
		if (vis[n][m] == target_vis)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int swimInWater(vector<vector<int>> &grid)
	{
		n = grid.size();
		m = grid[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i + 1][j + 1] = grid[i][j];
			}
		}
		int low = 0;
		int high = 2505;
		int mid;
		int ans = 1e9;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (func(mid) == true)
			{
				ans = min(ans, mid);
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		return ans;
	}
};