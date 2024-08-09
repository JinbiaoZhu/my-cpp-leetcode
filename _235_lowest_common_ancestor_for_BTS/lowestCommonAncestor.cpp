#include"lowestCommonAncestor.h"


// 注意: 这个题目的二叉树是二叉搜索树
// 确定递归函数的输入和输出
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	// 确定终止条件
	if (root == nullptr)
	{
		return root;
	}

	// 确定递归逻辑和常规输出
	if ((p->val - root->val) * (q->val - root->val) <= 0)
	{
		return root;
	}

	if (p->val > root->val && q->val > root->val)
	{
		return lowestCommonAncestor(root->right, p, q);
	}

	if (p->val < root->val && q->val < root->val)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	
	return nullptr;
}