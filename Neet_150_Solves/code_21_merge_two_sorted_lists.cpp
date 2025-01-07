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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		ListNode *head;
		if ((list1 == NULL) && (list2 == NULL))
		{
			return list1;
		}
		else if (list1 == NULL)
		{
			return list2;
		}
		else if (list2 == NULL)
		{
			return list1;
		}
		else
		{
			if (list1->val < list2->val)
			{
				head = list1;
				list1 = list1->next;
			}
			else
			{
				head = list2;
				list2 = list2->next;
			}
		}
		ListNode *now = head;
		while ((list1 != NULL) && (list2 != NULL))
		{
			if (list1->val < list2->val)
			{
				now->next = list1;
				list1 = list1->next;
			}
			else
			{
				now->next = list2;
				list2 = list2->next;
			}
			now = now->next;
		}
		if (list1 != NULL)
		{
			now->next = list1;
		}
		if (list2 != NULL)
		{
			now->next = list2;
		}
		return head;
	}
};