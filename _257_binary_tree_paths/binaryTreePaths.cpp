#include "binaryTreePaths.h"

// 确定递归函数的输入输出
void traverse(TreeNode* node, vector<int>& path, vector<string>& path_string)
{
	path.push_back(node->val);

	// 确定递归函数的终止条件
	if (node->left == nullptr && node->right == nullptr) 
	{
		string spath;
		for (int i = 0; i < path.size()-1; i++)
		{
			spath += to_string(path.at(i));
			spath += "->";
		}
		spath += to_string(path.at(path.size() - 1));
		path_string.push_back(spath);
		return;
	}

	if (node->left)
	{
		traverse(node->left, path, path_string);
		path.pop_back();
	}
	if (node->right) 
	{
		traverse(node->right, path, path_string);
		path.pop_back();
	}
}

vector<string> getPath(TreeNode* root)
{
	vector<string> result;
	vector<int> path;
	traverse(root, path, result);
	return result;
}
