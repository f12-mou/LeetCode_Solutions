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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<int> adj[2005];
		vector<vector<int>> ans;
		queue<pair<TreeNode *, int>> q;
		if (root == NULL)
			return ans;
		int maxi = 1;
		q.push({root, 1});
		while (q.empty() == false)
		{
			pair<TreeNode *, int> p = q.front();
			q.pop();
			int now_depth = p.second;
			TreeNode *now = p.first;
			adj[now_depth].push_back(now->val);
			maxi = max(maxi, now_depth);
			if (now->left != NULL)
			{
				q.push({now->left, now_depth + 1});
			}
			if (now->right != NULL)
			{
				q.push({now->right, now_depth + 1});
			}
		}
		for (int i = 1; i <= maxi; i++)
		{
			vector<int> hehe = adj[i];
			ans.push_back(hehe);
		}
		return ans;
	}
};