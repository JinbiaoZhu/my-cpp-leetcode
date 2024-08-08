#include "hasPathSum.h"


// 确定函数的输入输出
bool hasPathSum(TreeNode* root, int targetSum)
{
    // 确定终止条件
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

    // 确定递归逻辑和输出
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
