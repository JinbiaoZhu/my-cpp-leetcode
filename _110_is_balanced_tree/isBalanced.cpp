#include "isBalanced.h"

// ȷ���ݹ麯�����������
int getDepth(TreeNode* node)
{
    // ȷ���ݹ麯������ֹ����
    if (node == nullptr) 
    {
        return 0;
    }

    // ȷ���ݹ麯���������߼��ͷ����߼�
    int leftHeight = getDepth(node->left);
    int rightHeight = getDepth(node->right);
    if (leftHeight == -1 || rightHeight == -1) 
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) <= 1) 
    {
        return 1 + max(leftHeight, rightHeight);
    }
    else
    {
        return -1;
    }
}

bool isBalanced(TreeNode* root)
{
    if (getDepth(root) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
