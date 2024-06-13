#include "BasicMethod.h"
#include<math.h>

bool BasicMethod::isValidAnagram(string s, string t)
{
    int vocab[26] = { 0 };

    for (int i = 0; i < s.size(); i++)
    {
        cout  << s[i] - 'a' << " ";
        vocab[s[i] - 'a'] += 1;
    }

    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] - 'a' << " ";
        vocab[t[i] - 'a'] -= 1;
    }

    int total = 0;
    for (int i = 0; i < sizeof(vocab) / sizeof(vocab[0]); i++) 
    {
        total += abs(vocab[i]);
    }

    if (total == 0) { return true; }
    else { return false; }
}
