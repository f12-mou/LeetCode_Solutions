/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{

		auto compare = [](ListNode *a, ListNode *b)
		{
			return a->val > b->val;
		};

		priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> pq(compare);

		for (ListNode *list : lists)
		{
			if (list != nullptr)
			{
				pq.push(list);
			}
		}

		ListNode *dummy = new ListNode(0);
		ListNode *tail = dummy;

		while (!pq.empty())
		{
			// Get the smallest element (top of the heap)
			ListNode *smallest = pq.top();
			pq.pop();

			tail->next = smallest;
			tail = tail->next;

			if (smallest->next != nullptr)
			{
				pq.push(smallest->next);
			}
		}

		return dummy->next;
	}
};