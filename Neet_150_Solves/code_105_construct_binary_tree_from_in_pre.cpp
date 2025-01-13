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
	int pre_arr[3005];
	int in_arr[3005];
	int n_pre;
	int n_in;

	map<int, int> mp_pre, mp_in;

	TreeNode *func(int pos_pre, int start_in, int end_in)
	{
		if (pos_pre >= n_pre)
			return NULL;
		if (start_in > end_in)
			return NULL;

		int val = pre_arr[pos_pre];

		cout << "in preArr: pos: " << pos_pre << " val: " << val << endl;

		TreeNode *now = new TreeNode(pre_arr[pos_pre]);

		int in_koi = mp_in[val];
		cout << "in _koi " << in_koi << endl;

		int amar_left = 1e9, amar_right = 1e9;

		for (int i = in_koi + 1; i <= end_in; i++)
		{
			int k = in_arr[i];
			int edike = mp_pre[k];
			amar_right = min(amar_right, edike);
		}
		cout << "amar right: " << amar_right << endl;
		if (amar_right == 1e9)
		{
			now->right = NULL;
		}
		else
		{
			now->right = func(amar_right, in_koi + 1, end_in);
		}

		now->left = func(pos_pre + 1, start_in, in_koi - 1);
		return now;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		n_pre = preorder.size();
		n_in = inorder.size();

		for (int i = 1; i <= n_pre; i++)
		{
			pre_arr[i - 1] = preorder[i - 1];
			mp_pre[pre_arr[i - 1]] = i - 1;
		}
		for (int i = 1; i <= n_in; i++)
		{
			in_arr[i - 1] = inorder[i - 1];
			mp_in[in_arr[i - 1]] = i - 1;
		}

		return func(0, 0, n_in - 1);
	}
};