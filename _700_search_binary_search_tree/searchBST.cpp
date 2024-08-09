#include "searchBST.h"

// 确定递归函数输入输出
TreeNode* searchBST(TreeNode* root, int val)
{
    // 确定递归终止条件
	if (root==nullptr)
	{
		return nullptr;
	}
	
	// 确定递归函数递归逻辑和常规输出
	if (root->val == val)
	{
		return root;
	}

	TreeNode* temp = nullptr;

	// 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值
	if (root->left && root->val > val)
	{
		temp = searchBST(root->left, val);
	}

	if (root->right && root->val < val)
	{
		temp = searchBST(root->right, val);
	}

	return temp;
}
