#pragma once
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x);
};

TreeNode* buildTree(vector<int>& data);
