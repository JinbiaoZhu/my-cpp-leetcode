#include "isBalanced.h"

// 确定递归函数的输入输出
int getDepth(TreeNode* node)
{
    // 确定递归函数的终止条件
    if (node == nullptr) 
    {
        return 0;
    }

    // 确定递归函数的运行逻辑和返回逻辑
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
