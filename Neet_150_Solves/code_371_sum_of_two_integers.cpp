class Solution
{
public:
	int getSum(int a, int b)
	{
		while (b != 0)
		{
			// Calculate carry
			int carry = a & b;

			// Sum without carry
			a = a ^ b;

			// Shift carry to the left
			b = carry << 1;
		}
		return a;
	}
};