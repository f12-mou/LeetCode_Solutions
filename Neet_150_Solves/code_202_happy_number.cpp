class Solution
{
public:
	bool isHappy(int n)
	{
		map<int, int> mp;
		mp[n] = 1;
		while (1)
		{
			int n2 = n;
			int sum = 0;
			while (n2 > 0)
			{
				int rem = n2 % 10;
				n2 = n2 / 10;
				sum += (rem * rem);
			}
			n = sum;
			if (mp.count(n) != 0)
			{
				if (mp[n] == 1)
				{
					break;
				}
			}
			else
			{
				mp[n] = 1;
			}
		}
		if (n == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};