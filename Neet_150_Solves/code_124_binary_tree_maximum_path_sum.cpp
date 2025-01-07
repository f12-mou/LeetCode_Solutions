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
int ans;
int indiv;
class Solution
{
public:
	int func(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		indiv = max(indiv, root->val);
		int lefte = 0;
		int righte = 0;
		lefte = func(root->left);
		righte = func(root->right);
		ans = max(ans, root->val + max(lefte, righte));
		ans = max(ans, root->val + (lefte + righte));
		return max(root->val, root->val + max(lefte, righte));
	}
	int maxPathSum(TreeNode *root)
	{
		ans = -20000;
		indiv = -20000;
		func(root);
		ans = max(ans, indiv);
		// cout<<ans<<endl;
		return ans;
	}
};