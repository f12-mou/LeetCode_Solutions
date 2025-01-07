class Solution
{
public:
	int hammingWeight(int n)
	{
		int hehe = __builtin_popcount(n);
		return hehe;
	}
};