#include "wordBreak.h"
#include"utils.h"

bool wordBreak(string s, vector<string>& wordDict)
{
    int bagSize = s.size();
    int wordNum = wordDict.size();

    // 1. ȷ����̬�滮���� dp[i] ��ʾ�ַ�������Ϊ i ʱ���Ƿ���Բ�ֳ��ֵ��ڲ��ĵ���
    vector<int> dp(bagSize + 1, false);

    // 3. ȷ����̬�滮����ĳ�ʼ�� dp[0] = true
    dp[0] = true;

    // 4. ȷ����̬�滮�ı���˳��: ���ַ�������ÿ������
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i - j >= 0)
            {
                // 2. ȷ����̬�滮���Ʊ��ʽ: dp[i] = true if (s.substr(i,j) in wordDict) && dp[i] == true
                string temp = s.substr(j, i - j);
                if (isInDict(temp, wordDict) && dp[j])
                {
                    dp[i] = true;
                }
            }
        }
    }

    // 5. �˹�ģ����ֵ���
    print_vector(dp);

    return dp[bagSize];
}


bool isInDict(string& s, vector<string>& wordDict) 
{
    for (string _s : wordDict) 
    {
        if (s == _s)
        {
            return true;
        }
    }
    return false;
}
