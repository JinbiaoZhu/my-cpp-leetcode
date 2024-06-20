#include <iostream>
#include<string>

using namespace std;


int main()
{
    std::cout << "Hello World!\n";

    string s;
    while (getline(cin,s)) 
    {
        if (s.empty()) 
        {
            break;
        }

        int lastIndex = s.size() - 1;
        int numberCount = 0;
        for (int i = 0; i < s.size() ; i++) 
        {
            if ('0' <= s[i] && s[i] <= '9') 
            {
                numberCount++;
            }
        }

        s.resize(s.size() + numberCount * 5);
        int newIndex = s.size() - 1;

        while (true)
        {
            if (lastIndex < 0) 
            {
                break;
            }

            if ('0' <= s[lastIndex] && s[lastIndex] <= '9') 
            {
                s[newIndex] = 'r'; newIndex--;
                s[newIndex] = 'e'; newIndex--;
                s[newIndex] = 'b'; newIndex--;
                s[newIndex] = 'm'; newIndex--;
                s[newIndex] = 'u'; newIndex--;
                s[newIndex] = 'n'; newIndex--;
            }
            else
            {
                s[newIndex] = s[lastIndex]; newIndex--;
            }

            lastIndex--;

        }
        cout << s << endl;
    }

    cin.get();
    return 0;
}
