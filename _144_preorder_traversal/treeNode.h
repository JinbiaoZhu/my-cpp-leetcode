#pragma once
#include<vector>

using namespace std;

struct treeNode
{
	int nodeValue;
	treeNode* left;
	treeNode* right;
	treeNode();
	treeNode(int x);
	treeNode(int x, treeNode* left, treeNode* right);
};

treeNode* buildTree(const std::vector<int>& values, int index);

