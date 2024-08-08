#include "findBottomLeftValue.h"
#include<limits.h>

long long int MAX_DEPTH = _I64_MIN;

int findBottomLeftValue(TreeNode* root)
{
	int current_depth = 0;
	int result = 0;
	getMaxDepth(root, current_depth, result);
	return result;
}

// 确定递归函数的输入输出
void getMaxDepth(TreeNode* root, int current_depth, int & result)
{
	// 确定终止递归的条件
	if (root->left == nullptr && root->right == nullptr)
	{
		if (current_depth > MAX_DEPTH)
		{
			MAX_DEPTH = current_depth;
			result = root->val;
			return;
		}
		else
		{
			return;
		}
	}

	if (root->left)
	{
		current_depth++;
		getMaxDepth(root->left, current_depth, result);
		current_depth--;
	}

	if (root->right)
	{
		current_depth++;
		getMaxDepth(root->right, current_depth, result);
		current_depth--;
	}
}
