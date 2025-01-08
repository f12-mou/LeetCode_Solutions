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
	bool ok;
	pair<int, int> func(TreeNode *root)
	{
		bool leftOkay = true;
		bool rightOkay = true;

		int leftSend = root->val;
		int rightSend = root->val;
		int minRight = root->val;
		int maxiLeft = root->val;

		if (root->left != NULL)
		{
			pair<int, int> p = func(root->left);
			maxiLeft = p.first;
			leftSend = max(leftSend, p.first);
			leftSend = max(leftSend, p.second);

			rightSend = min(rightSend, p.first);
			rightSend = min(rightSend, p.second);

			if (maxiLeft >= root->val)
			{
				leftOkay = false;
			}
			leftSend = max(leftSend, maxiLeft);
		}
		if (root->right != NULL)
		{

			pair<int, int> p = func(root->right);
			minRight = p.second;

			leftSend = max(leftSend, p.first);
			leftSend = max(leftSend, p.second);

			rightSend = min(rightSend, p.first);
			rightSend = min(rightSend, p.second);

			if (minRight <= root->val)
			{
				rightOkay = false;
			}
			rightSend = min(rightSend, minRight);
		}

		cout << "root val: " << root->val << " leftSend: " << leftSend << " rightSend " << rightSend << endl;

		ok = ok & leftOkay & rightOkay;
		return {leftSend, rightSend};
	}

	bool isValidBST(TreeNode *root)
	{
		ok = true;
		func(root);
		return ok;
	}
};