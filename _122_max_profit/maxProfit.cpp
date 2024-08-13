#include "maxProfit.h"

int maxProfit(vector<int>& prices)
{
    int result = 0;
    vector<int> profits;
	for (int i = 1; i < prices.size(); i++)
	{
		profits.push_back(prices[i] - prices[i - 1]);
	}
	for (int j = 0; j < profits.size(); j++)
	{
		if (profits[j] >= 0) 
		{
			result += profits[j];
		}
	}

	return result;
}
