class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		map<char, int> mp;
		int ans = 0, leftIdx = 0, rightIdx = 0, n = s.size();
		for (int i = 0; i < n; i++)
		{
			rightIdx = i;
			while (leftIdx < i && (mp[s[i]] + 1 >= 2))
			{
				mp[s[leftIdx]]--;
				leftIdx++;
			}
			mp[s[i]]++;
			ans = max(ans, rightIdx - leftIdx + 1);
		}
		return ans;
	}
};