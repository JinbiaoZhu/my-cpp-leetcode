#include "rightSideView.h"
#include"TreeNode.h"
#include<vector>
#include<queue>

using namespace std;

vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> queue;
    if (root==nullptr) 
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
            TreeNode* tmp = queue.front();
            queue.pop();
            if (i == size - 1) 
            {
                result.push_back(tmp->val);
            }
            if (tmp->left) 
            {
                queue.push(tmp->left);
            }
            if (tmp->right)
            {
                queue.push(tmp->right);
            }
        }
    }
    return result;
}
