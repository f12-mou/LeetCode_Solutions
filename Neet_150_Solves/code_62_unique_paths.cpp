class Solution
{
public:
	int N, M;
	int dp[105][105];
	int func(int row, int col)
	{
		if (row <= 0 || col <= 0 || row > N || col > M)
			return 0;
		if (row == N && col == M)
			return 1;
		if (dp[row][col] != -1)
			return dp[row][col];
		dp[row][col] = func(row + 1, col) + func(row, col + 1);
		return dp[row][col];
	}
	int uniquePaths(int m, int n)
	{
		N = m;
		M = n;
		memset(dp, -1, sizeof(dp));
		return func(1, 1);
	}
};