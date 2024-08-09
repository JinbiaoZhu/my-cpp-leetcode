#include "lowestCommonAncestor.h"

// 确定递归函数的输入和输出
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // 确定终止条件
	if (root==nullptr || root->val==p->val || root->val==q->val)
	{
		return root;
	}

	// 确定递归函数的递归逻辑和常规输出
	// step3. 对整个树递归
	TreeNode* left_node = lowestCommonAncestor(root->left, p, q);  // 左
	TreeNode* right_node = lowestCommonAncestor(root->right, p, q);  // 右
	if (left_node == nullptr && right_node != nullptr)
	{
		return right_node;
	}

	if (left_node != nullptr && right_node == nullptr)
	{
		return left_node;
	}

	if (left_node != nullptr && right_node != nullptr)
	{
		return root;
	}

    return nullptr;
}
