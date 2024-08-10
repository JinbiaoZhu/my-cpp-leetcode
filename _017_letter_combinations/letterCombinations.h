#pragma once
#include<vector>
#include<string>

using namespace std;

vector<string> letterCombinations(string digits);
void backtrack(vector<string>& total_result, string& single_result, string& digits, int startIndex);
string charDigit2String(char digits);