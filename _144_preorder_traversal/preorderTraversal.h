#pragma once
#include<vector>
#include"treeNode.h"

using namespace std;

void traversalSingleNode(treeNode* treenode, vector<int> & result);
vector<int> preorderTraversal(treeNode* firstNode);
vector<int> preorderTraversalforStack(treeNode* firstNode);