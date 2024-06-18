#include "reverse_string.h"
#include <iostream>
#include <string>

using namespace std;

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        if (i + k < s.size()) 
        {
            int left = i;
            int right = i + k-1;

            while (left < right)
            {
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
        }
        else 
        {
            int left = i;
            int right = s.size()-1;

            while (left < right)
            {
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }

        }


    }
    return s;
}
