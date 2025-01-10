/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	bool ok = true;

	int func(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int h1 = 1 + func(root->left);
		int h2 = 1 + func(root->right);
		if (abs(h1 - h2) <= 1)
		{
			// ok
		}
		else
		{
			ok = false;
		}
		return max(h1, h2);
	}
	bool isBalanced(TreeNode *root)
	{
		func(root);
		return ok;
	}
};