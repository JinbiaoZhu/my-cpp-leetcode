#include "lemonadeChange.h"

bool lemonadeChange(vector<int>& bills)
{
    vector<int> myMoney(3, 0);

	for (int i = 0; i < bills.size(); i++)
	{
		pair<bool, vector<int>> can_change = canChange(bills[i], myMoney);
		if (can_change.first)
		{
			for (int i = 0; i < can_change.second.size(); i++)
			{
				myMoney[i] += can_change.second[i];
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

pair<bool, vector<int>> canChange(int money, vector<int>& myMoney)
{
	if (money == 5)
	{
		return pair<bool, vector<int>>{true, vector<int>{1,0,0}};
	}
	else if (money == 10)
	{
		if (myMoney[0] >= 1)
		{
			return pair<bool, vector<int>>{true, vector<int>{-1, 1, 0}};
		}
		else
		{
			return pair<bool, vector<int>>{false, vector<int>{0, 1, 0}};
		}
	}
	else
	{
		if (myMoney[0] >= 1 && myMoney[1] >= 1)
		{
			return pair<bool, vector<int>>{true, vector<int>{-1, -1, 1}};
		}
		else if (myMoney[0] >= 3)
		{
			return pair<bool, vector<int>>{true, vector<int>{-3, 0, 1}};
		}
		else
		{
			return pair<bool, vector<int>>{false, vector<int>{0, 0, 1}};
		}
	}
}