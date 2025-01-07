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
	int goodNodes(TreeNode *root)
	{
		int ans = dfs(root, root->val);
		return ans;
	}
	int dfs(TreeNode *root, int maxi_so_far)
	{
		int now = 0;
		int next_val = maxi_so_far;
		if (root->val > maxi_so_far)
		{
			next_val = root->val;
		}
		if (maxi_so_far > root->val)
		{
			// natada
		}
		else
		{
			now = 1;
		}
		if (root->left != NULL)
		{
			now += (dfs(root->left, next_val));
		}
		if (root->right != NULL)
		{
			now += (dfs(root->right, next_val));
		}
		return now;
	}
};