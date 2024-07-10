#include "removeElement.h"

int removeElement(vector<int>& nums, int val)
{

    int slowIndex = 0;
    int fastIndex = 0;

    while (true)
    {
        if (fastIndex >= nums.size())
        {
            break;
        }

        if (nums.at(fastIndex) == val)
        {
            fastIndex++;
        }
        else 
        {
            nums.at(slowIndex) = nums.at(fastIndex);
            slowIndex++;
            fastIndex++;
        }
        
    }
    return slowIndex;
}
