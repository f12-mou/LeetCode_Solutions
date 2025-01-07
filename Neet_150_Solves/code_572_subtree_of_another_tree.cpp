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
	TreeNode *sub;

	bool func(TreeNode *root1, TreeNode *root2)
	{
		if (root1 != NULL)
		{
			if (root2 != NULL) //
			{
				bool res = true;
				if (root1->val != root2->val)
				{
					return false;
				}
				else
				{
					res = res & func(root1->left, root2->left);
					res = res & func(root1->right, root2->right);
					return res;
				}
			}
			else
			{
				return false;
			}
		}
		else // root1 is NULL
		{
			if (root2 == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool dfs(TreeNode *root)
	{
		if (root == NULL)
		{
			if (sub == NULL)
				return true;
			return false;
		}
		bool res = func(root, sub);
		res = res | dfs(root->left);
		res = res | dfs(root->right);
		return res;
	}

	bool isSubtree(TreeNode *root, TreeNode *subRoot)
	{
		sub = subRoot;
		bool res = dfs(root);
		return res;
	}
};