#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string n, x, y;
    vector<int> x_container, y_container;
    
    getline(cin,n);
    getline(cin, x);
    getline(cin, y);

    int n_new = stoi(n);

    int current_index = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == ' ')
        {
            x_container.push_back(stoi(x.substr(current_index, i - current_index - 1)));
            current_index = i + 1;
        }
    }

    for (int i = 0; i < x_container.size(); i++)
    {
        cout << x_container[i] << endl;
    }


    cout << n << endl << x << endl << y << endl;

    return 0;
}