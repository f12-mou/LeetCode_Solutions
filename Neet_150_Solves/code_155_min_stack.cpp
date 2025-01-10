#include <stack>
#include <climits>

class MinStack
{
public:
	std::stack<long long> st;
	long long min;

	MinStack()
	{
		min = LLONG_MAX;
	}

	void push(int val)
	{
		if (st.empty())
		{
			min = val;
			st.push(val);
		}
		else if (val >= min)
		{
			st.push(val);
		}
		else
		{
			st.push(2LL * val - min);
			min = val;
		}
	}

	void pop()
	{
		if (st.empty())
			return;

		long long topval = st.top();
		st.pop();
		if (topval < min)
		{
			min = 2LL * min - topval;
		}
	}

	int top()
	{
		if (st.empty())
			return -1;

		long long topval = st.top();
		if (topval < min)
		{
			return static_cast<int>(min);
		}
		else
		{
			return static_cast<int>(topval);
		}
	}

	int getMin()
	{
		return static_cast<int>(min);
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */