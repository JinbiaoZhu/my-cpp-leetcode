#include "convertBST.h"


TreeNode* convertBST(TreeNode* root)
{
	int prev = 0;
	reverse_traverse(root, prev);
	return root;
}

// ȷ���ݹ麯�������������
void reverse_traverse(TreeNode* node, int& prev)
{

    // ȷ���ݹ麯������ֹ����
	if (node==nullptr)
	{
		return;
	}

	// ȷ���ݹ��߼��ͳ������
	// node != nullptr
	reverse_traverse(node->right, prev);
	node->val += prev;
	prev = node->val;
	reverse_traverse(node->left,prev);
}
