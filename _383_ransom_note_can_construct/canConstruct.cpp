#include "canConstruct.h"
#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

bool canConstruct_solution1(string ransomNote, string magazine)
{
	unordered_map<char, int> temp;
	for (int i = 0; i < magazine.size(); i++) 
	{
		char t_char = magazine[i];
		cout << "add " << t_char << "." << endl;
		if (temp.find(t_char) != temp.end())
		{
			temp[t_char]++;
		}
		else 
		{
			temp.insert({ t_char ,1 });
		}
	}

	unordered_map<char, int>::iterator temp_iterator;
	for (temp_iterator=temp.begin(); temp_iterator!=temp.end(); ++temp_iterator)
	{
		cout << "char: " << temp_iterator->first << " value: " << temp_iterator->second << endl;
	}

	for (int j = 0; j < ransomNote.size(); j++)
	{
		char t_char = ransomNote[j];
		if (temp.find(t_char) != temp.end())
		{
			cout << "Here " << t_char << endl;
			temp[t_char]-=1;
			if (temp[t_char] < 0) 
			{
				cout << "Not enough." << endl;
				return false;
			}
		}
		else 
		{

			return false;
		}
	}

	return true;
}

bool canConstruct_solution2(string ransomNote, string magazine) 
{
	int arr[26] = { 0 };
	for (int i = 0; i < magazine.size(); i++)
	{
		char t_char = magazine[i];
		cout << "add " << t_char << "." << endl;
		arr[t_char - 'a'] += 1;
	}
	
	for (int j = 0; j < ransomNote.size(); j++)
	{
		char t_char = ransomNote[j];

		cout << "Here " << t_char << endl;
		arr[t_char - 'a'] -= 1;
		if (arr[t_char - 'a'] < 0)
		{
			cout << "Not enough." << endl;
			return false;
		}
	}

	return true;
}
