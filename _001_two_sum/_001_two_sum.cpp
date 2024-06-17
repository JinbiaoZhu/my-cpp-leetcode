#include <iostream>
#include<vector>
#include "two_sum.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<int> nums = { 3,2,4 };
    int target = 6;

    vector<int> result = twoSum(nums, target);

    for (const int& i : result) 
    {
        cout << i << " ";
    }

    cin.get();
    return 0;
}
