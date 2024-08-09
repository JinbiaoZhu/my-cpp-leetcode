#include "findMode.h"
#include<map>
#include<algorithm>

using namespace std;

vector<int> findMode(TreeNode* root)
{
    vector<int> traverse_result = levelTraverse(root);

    map<int, int> value_frequency_map;
    for (int i = 0; i < traverse_result.size(); i++)
    {
        value_frequency_map[traverse_result.at(i)]++;
    }

    int max_frequency = 0;
    for (const auto& pair: value_frequency_map)
    {
        if (pair.second>max_frequency)
        {
            max_frequency = pair.second;
        }
    }

    vector<int> modes;
    for ( const auto& pair: value_frequency_map)
    {
        if (pair.second == max_frequency) 
        {
            modes.push_back(pair.first);
        }
    }

    return modes;
}
