#include "lowestCommonAncestor.h"

// ȷ���ݹ麯������������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // ȷ����ֹ����
	if (root==nullptr || root->val==p->val || root->val==q->val)
	{
		return root;
	}

	// ȷ���ݹ麯���ĵݹ��߼��ͳ������
	// step3. ���������ݹ�
	TreeNode* left_node = lowestCommonAncestor(root->left, p, q);  // ��
	TreeNode* right_node = lowestCommonAncestor(root->right, p, q);  // ��
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
