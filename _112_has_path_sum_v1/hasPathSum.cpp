#include "hasPathSum.h"


// ȷ���������������
bool hasPathSum(TreeNode* root, int targetSum)
{
    // ȷ����ֹ����
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) 
    {
        if (root->val == targetSum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // ȷ���ݹ��߼������
    if (root->left)
    {
        targetSum -= root->left->val;
        if (hasPathSum(root->left, targetSum))
        {
            return true;
        }
        targetSum += root->left->val;
    }
    if (root->right)
    {
        targetSum -= root->right->val;
        if (hasPathSum(root->right, targetSum))
        {
            return true;
        }
        targetSum += root->right->val;
    }

    return false;
}
