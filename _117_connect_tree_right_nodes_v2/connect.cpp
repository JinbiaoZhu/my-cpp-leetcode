#include "connect.h"
#include<queue>

using namespace std;

TreeNode* connect(TreeNode* root)
{
    queue<TreeNode*> queue;

    if (root == nullptr) 
    {
        return nullptr;
    }
    else
    {
        queue.push(root);
    }

    while (!queue.empty())
    {
        int size = queue.size();

        for (int i = 0; i < size; i++) 
        {
            TreeNode* temp = queue.front();
            queue.pop();
            if (i != size-1 && queue.front() != nullptr)
            {
                temp->next = queue.front();
            }
            else if (i != size - 1 && queue.front() == nullptr)
            {
                TreeNode* null_temp = queue.front();
                queue.pop();
                temp->next = queue.front();
            }
            else
            {
                temp->next = nullptr;
            }
            if (temp->left) 
            {
                queue.push(temp->left);
            }
            if (temp->right)
            {
                queue.push(temp->right);
            }
        }
    }

    return root;
}

vector<int> traverse(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> queue;

    if (root == nullptr) 
    {
        return result;
    }
    else
    {
        queue.push(root);
    }

    while (!queue.empty())
    {
        int size = queue.size();
        
        for (int i = 0; i < size; i++)
        {
            TreeNode* temp = queue.front();
            queue.pop();
            if (temp == nullptr) 
            {
                TreeNode* temp = queue.front();
                queue.pop();
            }
            result.push_back(temp->val);
            
            if (temp->next == nullptr) 
            {
                result.push_back(-100);
            }
            
            if (temp->left)
            {
                queue.push(temp->left);
            }
            if (temp->right)
            {
                queue.push(temp->right);
            }
        }
    }

    return result;
}
