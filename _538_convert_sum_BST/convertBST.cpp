#include "convertBST.h"


TreeNode* convertBST(TreeNode* root)
{
	int prev = 0;
	reverse_traverse(root, prev);
	return root;
}

// 确定递归函数的输入与输出
void reverse_traverse(TreeNode* node, int& prev)
{

    // 确定递归函数的终止条件
	if (node==nullptr)
	{
		return;
	}

	// 确定递归逻辑和常规输出
	// node != nullptr
	reverse_traverse(node->right, prev);
	node->val += prev;
	prev = node->val;
	reverse_traverse(node->left,prev);
}
