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
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		int len = 0;
		ListNode *curr = head;
		while (curr != NULL)
		{
			len++;
			curr = curr->next;
		}
		// cout<<len<<endl;
		int pos = len - n + 1;
		if (pos == 1)
		{
			ListNode *curr = head->next;
			// free(head);
			return curr;
		}
		else if (pos == len)
		{
			ListNode *curr = head;
			ListNode *whom_to_delete = NULL;
			int koto = 1;
			while (curr != NULL)
			{
				koto++;
				cout << koto << endl;
				if (koto == len)
				{
					whom_to_delete = curr->next;
					curr->next = NULL;
					break;
				}
				curr = curr->next;
			}
			// free(whom_to_delete);
			return head;
		}
		else
		{
			ListNode *curr = head;
			ListNode *prev = curr;
			int koi = 1;

			while (curr != NULL)
			{
				koi++;
				if (koi == pos)
				{
					prev = curr->next;
					curr->next = curr->next->next;
					// free(prev);
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			return head;
		}
	}
};