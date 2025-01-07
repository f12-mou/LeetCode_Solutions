class Solution
{
public:
	bool isValid(string s)
	{
		bool ok = true;
		stack<char> stck;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stck.push(s[i]);
			}
			else if (s[i] == '{')
			{
				stck.push(s[i]);
			}
			else if (s[i] == '[')
			{
				stck.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (stck.empty())
				{
					ok = false;
					break;
				}
				char now = stck.top();
				stck.pop();
				if (now == '(')
					continue;
				else
				{
					ok = false;
					break;
				}
			}
			else if (s[i] == '}')
			{
				if (stck.empty())
				{
					ok = false;
					break;
				}
				char now = stck.top();
				stck.pop();
				if (now == '{')
					continue;
				else
				{
					ok = false;
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (stck.empty())
				{
					ok = false;
					break;
				}
				char now = stck.top();
				stck.pop();
				if (now == '[')
					continue;
				else
				{
					ok = false;
					break;
				}
			}
		}
		if (stck.empty() == false)
		{
			ok = false;
		}
		return ok;
	}
};