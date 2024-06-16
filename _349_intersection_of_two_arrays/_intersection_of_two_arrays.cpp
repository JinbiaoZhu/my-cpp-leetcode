#include<iostream>
#include<set>
#include<math.h>
#include<vector>
#include"_intersection_of_two_arrays.h"

using namespace std;

vector<int> intersection_of_two_arrays(int* array_1, int size_1, int* array_2, int size_2) 
{
	set<int> array_set;
	set<int> result;

	if (size_1 >= size_2) 
	{
		for (int i = 0; i < size_1; i++)
		{
			array_set.insert(array_1[i]);
		}

		for (int j = 0; j < size_2; j++) 
		{
			if (array_set.count(array_2[j]) == 1)
			{
				result.insert(array_2[j]);
			}
		}
	}
	else 
	{
		for (int i = 0; i < size_2; i++)
		{
			array_set.insert(array_2[i]);
		}

		for (int j = 0; j < size_1; j++)
		{
			if (array_set.count(array_1[j]) == 1)
			{
				result.insert(array_1[j]);
			}
		}
	}

	return vector<int>(result.begin(), result.end());
}

void printSet(vector<int> a_vector) 
{
	for (const int& i : a_vector) 
	{
		cout << i << " ";
	}

	cout << "End here" << endl;
}