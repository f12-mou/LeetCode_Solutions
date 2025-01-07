class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int n = matrix.size();
		int start = n - 1;
		int endIdx = 0;
		if (n % 2 == 0)
		{
			endIdx = 1;
		}
		int startRow = 1, startCol = 1, endRow = n, endCol = n;
		for (int i = start; i >= endIdx; i -= 2)
		{
			pair<int, int> first = {endRow, startCol};
			pair<int, int> sec = {startRow, startCol};
			pair<int, int> third = {startRow, endCol};
			pair<int, int> fourth = {endRow, endCol};
			for (int j = endRow; j > startRow; j--)
			{
				int temp = matrix[first.first - 1][first.second - 1];
				matrix[first.first - 1][first.second - 1] = matrix[fourth.first - 1][fourth.second - 1];
				matrix[fourth.first - 1][fourth.second - 1] = matrix[third.first - 1][third.second - 1];
				matrix[third.first - 1][third.second - 1] = matrix[sec.first - 1][sec.second - 1];
				matrix[sec.first - 1][sec.second - 1] = temp;
				first.first--;
				sec.second++;
				third.first++;
				fourth.second--;
			}
			startRow++;
			endRow--;
			startCol++;
			endCol--;
		}
	}
};