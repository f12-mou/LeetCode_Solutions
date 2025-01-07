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
	int ans;
	int dfs(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int val_1 = dfs(root->left);
		int val_2 = dfs(root->right);
		ans = max(ans, val_1 + val_2);
		return 1 + max(val_1, val_2);
	}
	int diameterOfBinaryTree(TreeNode *root)
	{
		ans = 0;
		dfs(root);
		return ans;
	}
};