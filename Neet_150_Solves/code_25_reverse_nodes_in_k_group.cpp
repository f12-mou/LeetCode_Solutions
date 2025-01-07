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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		ListNode *ansHead = NULL;
		vector<ListNode *> vec;

		ListNode *curr = head;
		ListNode *prev = NULL;
		while (curr != NULL)
		{
			cout << curr->val << endl;
			for (int i = 1; i <= k; i++)
			{
				if (curr == NULL)
					break;
				vec.push_back(curr);
				cout << "pushed back " << curr->val << endl;
				curr = curr->next;
			}
			if (vec.size() == k)
			{
				cout << "vec size: " << vec.size() << endl;
				if (ansHead == NULL)
				{
					ansHead = vec[k - 1];
				}
				for (int i = k - 1; i > 0; i--)
				{
					vec[i]->next = vec[i - 1];
				}
				vec[0]->next = NULL;
				if (prev != NULL)
				{
					prev->next = vec[k - 1];
				}
				prev = vec[0];
				cout << "here : prev: " << prev->val << endl;
				vec.clear();
			}
			else
			{
				if (prev == NULL)
				{
					return vec[0];
				}
				else
				{
					prev->next = vec[0];
				}
				break;
			}
		}
		return ansHead;
	}
};