class Solution
{
public:
	char s2[100005];
	char t2[100005];
	int preArr_s2[101][100005];
	int preArr_t2[101][100005];
	int n, m;
	int check_size = 52;

	string minWindow(string s, string t)
	{
		n = s.size();
		m = t.size();

		for (int i = 0; i < n; i++)
		{
			s2[i + 1] = s[i];
		}
		for (int i = 0; i < m; i++)
		{
			t2[i + 1] = t[i];
		}

		for (int i = 1; i <= n; i++)
		{
			char now = s2[i];
			for (int j = 1; j <= check_size; j++)
			{
				preArr_s2[j][i] = preArr_s2[j][i - 1];
			}
			if (now >= 'a' && now <= 'z')
				preArr_s2[now - 'a' + 1][i]++;
			else
			{
				preArr_s2[now - 'A' + 1 + 26][i]++;
			}
		}

		for (int i = 1; i <= m; i++)
		{
			char now = t2[i];
			for (int j = 1; j <= check_size; j++)
			{
				preArr_t2[j][i] = preArr_t2[j][i - 1];
			}
			if (now >= 'a' && now <= 'z')
				preArr_t2[now - 'a' + 1][i]++;
			else
			{
				preArr_t2[now - 'A' + 1 + 26][i]++;
			}
		}

		int low = min(n, m), high = n, mid, ans = -1;
		vector<pair<int, int>> vec;

		int final_len = 1e9;
		int final_idx;

		while (low <= high)
		{
			mid = (low + high) / 2;
			int len = mid;
			bool found = false;
			int idx = -1;
			for (int i = len; i <= n; i++)
			{
				bool ok = true;
				for (int j = 1; j <= check_size; j++)
				{
					int ase_koto = preArr_s2[j][i] - preArr_s2[j][i - len];
					int lagbe_koto = preArr_t2[j][m];
					if (ase_koto >= lagbe_koto)
					{
						// okayy
					}
					else
					{
						ok = false;
						break;
					}
				}
				if (ok == true)
				{
					found = true;
					idx = i;
					break;
				}
			}
			if (found == true)
			{
				vec.push_back({len, idx});
				if (len < final_len)
				{
					final_len = len;
					final_idx = idx;
				}
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		if (vec.empty())
		{
			return "";
		}
		else
		{

			string ans = s.substr(final_idx - final_len, final_len);
			return ans;
		}
	}
};