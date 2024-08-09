#include "trimBST.h"


// 确定递归函数的输入输出
TreeNode* trimBST(TreeNode* root, int low, int high)
{
	// 确定递归函数的终止条件
	if (root==nullptr)
	{
		return nullptr;
	}
	
	// 确定递归函数的递归逻辑和常规输出
	// 如果当前的节点值比区间最小值都要小，那么就舍弃左子树
	if (root->val < low)
	{
		TreeNode* right = trimBST(root->right, low, high);
		return right;
	}

	// 如果当前的节点值比区间最大值都要大，那么就舍弃右子树
	if (root->val > high)
	{
		TreeNode* left = trimBST(root->left, low, high);
		return left;
	}

	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);

	return root;
}
