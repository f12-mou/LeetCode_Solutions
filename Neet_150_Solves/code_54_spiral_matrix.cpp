
vector<int> ans;
int a[15][15];
int func(int startRow, int endRow, int startCol, int endCol)
{
	if (startRow > endRow)
		return 0;
	if (startCol > endCol)
		return 0;
	if (startCol == endCol)
	{
		for (int i = startRow; i <= endRow; i++)
		{
			ans.push_back(a[i][startCol]);
		}
		return 0;
	}
	if (startRow == endRow)
	{
		for (int i = startCol; i <= endCol; i++)
		{
			ans.push_back(a[startRow][i]);
		}
		return 0;
	}
	for (int i = startCol; i <= endCol; i++)
	{
		ans.push_back(a[startRow][i]);
	}
	for (int i = startRow + 1; i < endRow; i++)
	{
		ans.push_back(a[i][endCol]);
	}
	for (int i = endCol; i >= startCol; i--)
	{
		if (startRow != endRow)
		{
			ans.push_back(a[endRow][i]);
		}
	}
	for (int i = endRow - 1; i > startRow; i--)
	{
		ans.push_back(a[i][startCol]);
	}
	func(startRow + 1, endRow - 1, startCol + 1, endCol - 1);
	return 0;
}
class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				a[i][j] = matrix[i - 1][j - 1];
			}
		}
		ans.clear();
		func(1, row, 1, col);
		return ans;
	}
};