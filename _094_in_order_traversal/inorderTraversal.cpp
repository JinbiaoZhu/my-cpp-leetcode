#include "inorderTraversal.h"

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    singleNodeTraversal(root, result);
    return result;
}

void singleNodeTraversal(TreeNode* node, vector<int>& result)
{
    if (node == nullptr) 
    {
        return;
    }
    singleNodeTraversal(node->left, result);
    result.push_back(node->val);
    singleNodeTraversal(node->right, result);
}
