#pragma once
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	vector<TreeNode*> childs;
	TreeNode();
	TreeNode(int _val);
	TreeNode(int _val, vector<TreeNode*> _childs);
};

TreeNode* buildTree(vector<int>& data);