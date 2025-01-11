/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
	string ans;
	vector<int> vec;
	int n;
	int bias = 2000;

	// pre-order traversal
	void func(TreeNode *root)
	{
		if (root == NULL)
		{
			vec.push_back(bias);
			return;
		}
		vec.push_back(root->val);
		func(root->left);
		func(root->right);
	}

	string func2()
	{
		string ans = "";
		for (int i = 0; i < vec.size(); i++)
		{
			ans += to_string(vec[i]);
			if (i != (vec.size() - 1))
			{
				ans += ",";
			}
		}
		return ans;
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		func(root);
		string ans = func2();
		cout << ans << endl;
		return ans;
	}
	vector<int> vec2;

	void func3(string ans)
	{
		vector<int> comma_pos;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] == ',')
				comma_pos.push_back(i);
		}
		if (comma_pos.empty() == true)
		{
			vec2.push_back(bias);
			return;
		}
		for (int i = 0; i < comma_pos.size(); i++)
		{

			if (i == 0)
			{
				string now = ans.substr(0, comma_pos[0]);
				cout << "i: " << i << " now: " << now << endl;
				vec2.push_back(stoi(now));

				int now_pos = comma_pos[i];
				now = ans.substr(now_pos + 1, (comma_pos[i + 1] - 1 - comma_pos[i]));
				cout << "i: " << i << " now: " << now << endl;
				vec2.push_back(stoi(now));
			}
			else if (i == (comma_pos.size() - 1))
			{
				int now_pos = comma_pos[i];
				string now = ans.substr(now_pos + 1, (ans.size() - 1 - now_pos));
				cout << "i: " << i << " now: " << now << endl;
				vec2.push_back(stoi(now));
			}
			else
			{
				int now_pos = comma_pos[i];
				string now = ans.substr(now_pos + 1, (comma_pos[i + 1] - 1 - comma_pos[i]));
				cout << "i: " << i << " now: " << now << endl;
				vec2.push_back(stoi(now));
			}
		}
	}

	pair<TreeNode *, int> func4(int pos)
	{
		if (vec2[pos] == bias)
		{
			return {NULL, pos + 1};
		}
		TreeNode *now = new TreeNode(vec2[pos]);
		pair<TreeNode *, int> p = func4(pos + 1);
		now->left = p.first;
		pair<TreeNode *, int> p2 = func4(p.second);
		now->right = p2.first;
		return {now, p2.second};
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		func3(data);
		pair<TreeNode *, int> p = func4(0);
		return p.first;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));