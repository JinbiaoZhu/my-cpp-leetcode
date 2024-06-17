#include <iostream>
#include<vector>
#include"threeSum.h"

int main()
{
    std::cout << "Hello World!\n";

    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> result = threeSum_solution1(nums);

    for (int i = 0; i < result.size(); i++) 
    {
        cout << "[";
        for (int j=0;j<result[i].size();j++) 
        {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cin.get();
    return 0;
}
