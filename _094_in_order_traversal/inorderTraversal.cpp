#include "inorderTraversal.h"
#include<stack>

using namespace std;

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

vector<int> inorderTraversalforStack(TreeNode* root) 
{
    stack<TreeNode*> TreeNodeStack;
    vector<int> result;
    TreeNode* cur = root;

    while (cur != nullptr || !TreeNodeStack.empty())
    {

        if (cur != nullptr) 
        {
            TreeNodeStack.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = TreeNodeStack.top();
            TreeNodeStack.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }


    return result;
}


vector<int> inorderTraversalforStackv2(TreeNode* root) 
{
    stack<TreeNode*> TreeNodeStack;
    vector<int> result;

    if (root == nullptr) 
    {
        return result;
    }
    else
    {
        TreeNodeStack.push(root);
    }

    while (!TreeNodeStack.empty())
    {

        TreeNode* temp = TreeNodeStack.top();
        if (temp != nullptr) 
        {
            TreeNodeStack.pop();
            if (temp->right) 
            {
                TreeNodeStack.push(temp->right);
            }
            TreeNodeStack.push(temp);
            TreeNodeStack.push(NULL);
            if (temp->left) 
            {
                TreeNodeStack.push(temp->left);
            }
        }
        else
        {
            TreeNodeStack.pop();
            TreeNode* node = TreeNodeStack.top();
            TreeNodeStack.pop();
            result.push_back(node->val);
        }

    }


    return result;


}