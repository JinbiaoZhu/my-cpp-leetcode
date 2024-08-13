#include "candy.h"
#include<iostream>

using namespace std;

int candy(vector<int>& ratings)
{
    vector<int> left2right(ratings.size(), 1);
    vector<int> right2left(ratings.size(), 1);
	vector<int> candyInfo(ratings.size(), 1);

	// �Һ��Ӵ�������
	for (int i = 0; i < ratings.size(); i++)
	{
		if (i == 0) 
		{
			right2left[i] = NULL;
		}
		else
		{
			// i > 0
			right2left[i] = ratings[i] - ratings[i - 1];
		}
	}

	cout << "�Һ��Ӵ�������" << endl;
	for (int i = 0; i < right2left.size(); i++)
	{
		cout << right2left[i] << "\t";
	}
	cout << endl;

	///////////////////////////////////////////////////////////////////////////

	// ���Ӵ����Һ���
	for (int i = ratings.size()-1; i >= 0; i--)
	{
		if (i == ratings.size() - 1)
		{
			left2right[i] = NULL;
		}
		else
		{
			left2right[i] = ratings[i] - ratings[i + 1];
		}
	}

	cout << "���Ӵ����Һ���" << endl;
	for (int i = 0; i < left2right.size(); i++)
	{
		cout << left2right[i] << "\t";
	}
	cout << endl;

	//////////////////////////////////////////////////////////////////////////

	// ���� "�Һ��Ӵ�������" �����
	for (int i = 0; i < right2left.size(); i++)
	{
		if (right2left[i] > 0)
		{
			candyInfo[i] = candyInfo[i - 1] + 1;
		}
	}

	cout << "���� '�Һ��Ӵ�������' �����" << endl;
	for (int i = 0; i < candyInfo.size(); i++)
	{
		cout << candyInfo[i] << "\t";
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////////

	// ���� "���Ӵ����Һ���" �����
	for (int i = left2right.size()-1; i >= 0; i--)
	{
		if (left2right[i] > 0)
		{
			candyInfo[i] = max(candyInfo[i + 1] + 1, candyInfo[i]);
		}
	}

	cout << "���� '���Ӵ����Һ���' �����" << endl;
	for (int i = 0; i < candyInfo.size(); i++)
	{
		cout << candyInfo[i] << "\t";
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < candyInfo.size(); i++)
	{
		cout << candyInfo[i] << "\t";
	}
	cout << endl;

	int result = 0;
	for (int i = 0; i < candyInfo.size(); i++)
	{
		result += candyInfo[i];
	}

	return result;
}
