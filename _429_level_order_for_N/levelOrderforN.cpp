#include "levelOrderforN.h"
#include"queue"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
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
        vector<int> tmpResult;

        for (int i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            tmpResult.push_back(node->val);
            for (int index = 0; index < node->childs.size(); index++)
            {
                if (node->childs.at(index))
                {
                    queue.push(node->childs.at(index));
                }
            }
        }

        result.push_back(tmpResult);
    }

    return result;
}
