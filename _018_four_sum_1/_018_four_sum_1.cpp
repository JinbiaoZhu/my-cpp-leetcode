#include <iostream>
#include"four_sum.h"
#include<vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<int> nums = { 1,0,-1,0,-2,2 };
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    for (int i = 0; i < result.size(); i++) 
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cin.get();
    return 0;
}
