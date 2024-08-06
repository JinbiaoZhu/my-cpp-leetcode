#include "myComparation.h"

bool myComparation::operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.second > rhs.second;
}
