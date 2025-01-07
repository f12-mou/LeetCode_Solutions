#define ll long long
class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		ll now = n;
		vector<int> vec;
		for (int i = 0; i <= 31; i++)
		{
			if ((1LL << i) & now)
			{
				vec.push_back(1);
			}
			else
			{
				vec.push_back(0);
			}
		}
		while (vec.size() < 32)
		{
			vec.push_back(0);
		}
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
		}
		cout << endl;
		int ans = 0LL;
		reverse(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == 0)
				continue;
			ans = ans | (1LL << i);
		}
		return ans;
	}
};