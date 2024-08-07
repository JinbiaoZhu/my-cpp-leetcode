#include "TreeNode.h"
#include<vector>

using namespace std;

TreeNode::TreeNode()
{
	this->val = 0;
	vector<TreeNode*> _childs = { nullptr, nullptr, nullptr };
	this->childs = _childs;
}

TreeNode::TreeNode(int _val)
{
	this->val = _val;
	vector<TreeNode*> _childs = { nullptr, nullptr, nullptr };
	this->childs = _childs;
}

TreeNode::TreeNode(int _val, vector<TreeNode*> _childs)
{
	this->val = _val;
	this->childs = _childs;
}

TreeNode* buildTree(vector<int>& data)
{
	vector<TreeNode*> TreeNodeList;

	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) != -100) 
		{
			TreeNode* tmp = new TreeNode(data.at(i));
			TreeNodeList.push_back(tmp);
		}
		else
		{
			TreeNode* tmp = nullptr;
			TreeNodeList.push_back(tmp);
		}
	}

	for (int i = 0; 3 * i + 1 < TreeNodeList.size(); i++)
	{
		if (TreeNodeList.at(i)) 
		{
			TreeNodeList.at(i)->childs.at(0) = TreeNodeList.at(3 * i + 1);
			if (3 * i + 2 < TreeNodeList.size()) 
			{
				TreeNodeList.at(i)->childs.at(1) = TreeNodeList.at(3 * i + 2);
				if (3 * i + 3 < TreeNodeList.size()) 
				{
					TreeNodeList.at(i)->childs.at(2) = TreeNodeList.at(3 * i + 3);
				}
			}
		}
	}

	return TreeNodeList.at(0);
}
