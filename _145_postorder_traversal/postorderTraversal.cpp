#include "postorderTraversal.h"
#include<stack>

using namespace std;


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

vector<int> postorderTraversalforStack(TreeNode* firstNode)
{
	stack<TreeNode*> treeNodeStack;
	vector<int> result;

	if (firstNode == nullptr)
	{
		return result;
	}

	treeNodeStack.push(firstNode);
	while (!treeNodeStack.empty())
	{
		TreeNode* temp = treeNodeStack.top();
		treeNodeStack.pop();
		result.push_back(temp->val);
		if (temp->left)
		{
			treeNodeStack.push(temp->left);
		}
		if (temp->right)
		{
			treeNodeStack.push(temp->right);
		}
		
	}

	reverse(result.begin(), result.end());
	return result;
}

