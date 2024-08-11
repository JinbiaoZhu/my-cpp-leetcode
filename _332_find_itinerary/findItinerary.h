#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets);
bool backtrack(unordered_map<string, map<string, int>>& flightTable, vector<string>& result, int ticketNum);