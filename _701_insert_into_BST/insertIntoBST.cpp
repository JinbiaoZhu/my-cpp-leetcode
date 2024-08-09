#include "insertIntoBST.h"


// 注意: 这是二叉搜索树
TreeNode* insertIntoBST(TreeNode* root, int val)
{
	if (root==nullptr)
	{
		TreeNode* newNode = new TreeNode(val);
		return newNode;
	}

	if (root->val < val)
	{
		root->right = insertIntoBST(root->right, val);
	}
	if (root->val > val)
	{
		root->left = insertIntoBST(root->left, val);
	}

	return root;
}
