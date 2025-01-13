class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		bool ok = true;
		for (int i = 0; i < 9; i++)
		{
			// row wise cheeck
			vector<int> vec;
			set<int> st;
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				int val = board[i][j] - '1' + 1;
				vec.push_back(val);
				st.insert(val);
			}
			if (vec.size() != st.size())
			{
				ok = false;
				break;
			}
		}

		for (int i = 0; i < 9; i++)
		{
			// row wise cheeck
			vector<int> vec;
			set<int> st;
			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] == '.')
					continue;
				int val = board[j][i] - '1' + 1;
				vec.push_back(val);
				st.insert(val);
			}
			if (vec.size() != st.size())
			{
				ok = false;
				break;
			}
		}

		for (int i = 0; i < 9; i += 3)
		{
			for (int j = 0; j < 9; j += 3)
			{
				vector<int> vec;
				set<int> st;
				for (int ii = 0; ii <= 2; ii++)
				{
					for (int jj = 0; jj <= 2; jj++)
					{
						if (board[i + ii][j + jj] == '.')
							continue;
						int val = board[i + ii][j + jj] - '1' + 1;
						vec.push_back(val);
						st.insert(val);
					}
				}
				if (vec.size() != st.size())
				{
					ok = false;
					break;
				}
			}
			if (ok == false)
			{
				break;
			}
		}

		return ok;
	}
};