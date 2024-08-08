#include "sumOfLeftLeaves.h"

// 确定递归函数的输入和输出
int sumOfLeftLeaves(TreeNode* root)
{
    // 确定递归函数的终止条件
	if (root==nullptr)
	{
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) 
	{
		return 0;
	}

	// 确定函数递归逻辑和返回逻辑
	int left_sum = 0; int right_sum = 0;
	if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) 
	{
		left_sum = root->left->val;
	}
	else
	{
		left_sum = sumOfLeftLeaves(root->left);
	}

	right_sum = sumOfLeftLeaves(root->right);

	return left_sum + right_sum;
}
