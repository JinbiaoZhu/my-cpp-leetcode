#include <iostream>
#include "four_sum_count.h"
#include<iostream>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    
    // nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    // nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
    vector<int> nums1 = { 0 };
    vector<int> nums2 = { 0 };
    vector<int> nums3 = { 0 };
    vector<int> nums4 = { 0 };

    int count = fourSumCount(nums1, nums2, nums3, nums4);
    cout << "count:" << count << endl;

    cin.get();
    return 0;
}
