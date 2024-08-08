#include "isSymmetric.h"

// 确定递推输入输出
bool compare(TreeNode* left, TreeNode* right)
{
	// 确定终止条件
	if (left == nullptr && right != nullptr)
	{
		return false;
	}
	else if (left != nullptr && right == nullptr)
	{
		return false;
	}
	else if (left == nullptr && right == nullptr)
	{
		return true;
	}
	else if (left->val != right->val)
	{
		return false;
	}

	// 确定递推逻辑
	bool outside = compare(left->left, right->right);
	bool inside = compare(left->right, right->left);
	
	// 确定最终返回值
	bool isCompare = outside && inside;
	return isCompare;
}

bool isSymmetric(TreeNode* root)
{
	if (root==nullptr)
	{
		return true;
	}
	return compare(root->left, root->right);
}



