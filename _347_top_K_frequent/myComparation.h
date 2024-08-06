#pragma once
#include<iostream>

using namespace std;

class myComparation
{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs);
};

