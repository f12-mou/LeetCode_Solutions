class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		set<int> rows_baad;
		set<int> cols_baad;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 0)
				{
					rows_baad.insert(i);
					cols_baad.insert(j);
				}
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (rows_baad.count(i) != 0)
				{
					matrix[i][j] = 0;
				}
				if (cols_baad.count(j) != 0)
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};