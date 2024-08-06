#include<vector>
#include "sliding_window.h"
#include"MyQueue.h"

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    MyQueue myqueue;
    vector<int> result;

    for (int i = 0; i < k; i++) 
    {
        myqueue.push(nums.at(i));
    }

    result.push_back(myqueue.front());

    for (int i = k; i < size(nums); i++) 
    {
        myqueue.pop(nums[static_cast<vector<int, allocator<int>>::size_type>(i) - k]);
        myqueue.push(nums[i]);
        result.push_back(myqueue.front());
    }


    return result;
}
