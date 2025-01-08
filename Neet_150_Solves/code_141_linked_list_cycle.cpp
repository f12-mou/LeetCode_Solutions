/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		bool cycle = false;
		const int bigNum = 1e6;
		while (head != NULL)
		{
			if (head->next == NULL)
				break;
			if (head->next->val == bigNum)
			{
				cycle = true;
				break;
			}
			else
			{
				head->val = bigNum;
				head = head->next;
			}
		}
		return cycle;
	}
};