#include <iostream>
#include<string>
#include<vector>

using namespace std;

bool check(string& equation, int start_index, int end_index) 
{
	if (start_index - end_index <= 0)
	{
		return true;
	}

	for ( i = 0; i < length; i++)
	{

	}
}


string canBeAdd(string& equation)
{
	
}

int main()
{
	string n;
	getline(cin, n);
	int n_int = stoi(n);

	vector<string> buffer(n_int, "");

	int count_n = 0;
	while (true)
	{
		getline(cin, buffer[count_n]);
		count_n++;

		if (count_n >= n_int)
		{
			break;
		}
	}

	for (int i = 0; i < buffer.size(); i++)
	{
		string equation = buffer[i];
		string result = canBeAdd(equation);
		cout << result << endl;
	}

	return 0;
}



