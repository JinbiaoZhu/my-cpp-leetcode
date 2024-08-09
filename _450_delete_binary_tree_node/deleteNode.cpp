#include "deleteNode.h"


// 确定递归函数的输入和输出
TreeNode* deleteNode(TreeNode* root, int key)
{
    // 确定递归函数的终止条件
	if (root == nullptr)
	{
		return root;
	}

	// 确定递归逻辑和常规输出
	if (root->val == key)
	{
		// 1. 当前节点无 左节点 和 右节点
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		// 2. 有左节点 没有右节点
		if (root->left && root->right == nullptr)
		{
			auto returned_node = root->left;
			delete root;
			return returned_node;
		}
		// 3. 有右节点 没有左节点
		if (root->right && root->left == nullptr)
		{
			auto returned_node = root->right;
			delete root;
			return returned_node;
		}
		// 4. 既有左节点 又有右节点
		if (root->left && root->right)
		{
			TreeNode* cur = root->right;
			while (cur->left != nullptr) {
				cur = cur->left;
			}
			cur->left = root->left;
			TreeNode* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
	}

	if (root->val > key)
	{
		root->left = deleteNode(root->left, key);
	}

	if (root->val < key)
	{
		root->right = deleteNode(root->right, key);
	}

	return root;
}
