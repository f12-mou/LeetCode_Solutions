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
	vector<int> ans;
	bool vis[200];

	void func(TreeNode *root, int lvl)
	{
		if (root == NULL)
			return;
		if (vis[lvl] == false)
		{
			ans.push_back(root->val);
			vis[lvl] = true;
		}
		func(root->right, lvl + 1);
		func(root->left, lvl + 1);
	}
	vector<int> rightSideView(TreeNode *root)
	{
		func(root, 1);
		return ans;
	}
};