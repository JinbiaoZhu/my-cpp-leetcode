#pragma once
#include<vector>
#include<string>

using namespace std;

vector<string> restoreIpAddresses(string s);
void backtrack(vector<string>& result, string& path, string& s, int num_dot, int startIndex);
bool isValidNumber(string digit, int left, int right);
