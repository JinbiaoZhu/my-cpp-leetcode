#include "deleteNode.h"


// ȷ���ݹ麯������������
TreeNode* deleteNode(TreeNode* root, int key)
{
    // ȷ���ݹ麯������ֹ����
	if (root == nullptr)
	{
		return root;
	}

	// ȷ���ݹ��߼��ͳ������
	if (root->val == key)
	{
		// 1. ��ǰ�ڵ��� ��ڵ� �� �ҽڵ�
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		// 2. ����ڵ� û���ҽڵ�
		if (root->left && root->right == nullptr)
		{
			auto returned_node = root->left;
			delete root;
			return returned_node;
		}
		// 3. ���ҽڵ� û����ڵ�
		if (root->right && root->left == nullptr)
		{
			auto returned_node = root->right;
			delete root;
			return returned_node;
		}
		// 4. ������ڵ� �����ҽڵ�
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
