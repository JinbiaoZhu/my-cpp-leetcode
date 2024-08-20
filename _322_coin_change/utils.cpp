#include "utils.h"
#include<iostream>

using namespace std;

void print_vector(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
