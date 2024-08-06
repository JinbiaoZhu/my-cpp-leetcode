#include "postorderTraversal.h"



vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    traversalSingleNode(root, result);
    return result;

}

void traversalSingleNode(TreeNode* current, vector<int>& result)
{
    if (current == nullptr) 
    {
        return;
    }

    traversalSingleNode(current->left, result);
    traversalSingleNode(current->right, result);
    result.push_back(current->val);
}
