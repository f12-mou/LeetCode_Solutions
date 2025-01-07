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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int carry = 0;
		int sum = 0;
		ListNode head;
		ListNode *curr;
		curr = &head;
		while ((l1 != NULL) && (l2 != NULL))
		{
			int val1 = l1->val;
			int val2 = l2->val;
			cout << "val1 " << val1 << " val2: " << val2 << endl;
			sum = val1 + val2 + carry;
			if (sum >= 10)
			{
				int h = sum;
				carry = sum / 10;
				sum = sum % 10;
			}
			else
			{
				carry = 0;
			}
			ListNode *hehe;
			hehe = new ListNode(sum);
			curr->next = hehe;
			curr = hehe;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			int val1 = l1->val;
			int val2 = 0;

			sum = val1 + val2 + carry;
			if (sum >= 10)
			{
				int h = sum;
				carry = sum / 10;
				sum = sum % 10;
			}
			else
			{
				carry = 0;
			}

			ListNode *hehe;
			hehe = new ListNode(sum);
			curr->next = hehe;
			curr = hehe;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			int val1 = l2->val;
			int val2 = 0;
			sum = val1 + val2 + carry;
			if (sum >= 10)
			{
				int h = sum;
				carry = sum / 10;
				sum = sum % 10;
			}
			else
			{
				carry = 0;
			}

			ListNode *hehe;
			hehe = new ListNode(sum);
			curr->next = hehe;
			curr = hehe;
			l2 = l2->next;
		}
		if (carry != 0)
		{
			ListNode *hehe;
			hehe = new ListNode(carry);
			curr->next = hehe;
			curr = hehe;
		}
		return head.next;
	}
};