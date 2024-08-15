#include "integerBreak.h"
#include<vector>
#include<iostream>

using namespace std;

int integerBreak(int n)
{
    // 1. ȷ����̬�滮��������±�
    //    dp[i] ��ʾ�� i ���������˻�
    vector<int> dp(n + 1, NULL);

    // 3. ȷ����̬�滮�ĳ�ʼ����
    //    dp[2] =1 ��Ŀ���� i >= 2
    dp[2] = 1;

    // 4. ȷ����̬�滮�ı�������
    //    ��ǰ����, ��С�������
    for (int i = 3; i <= n; i++)
    {
        // 2. ȷ����̬�滮�ĵ��ƹ�ʽ
        //    ���� i = j + (i-j) ����ȡ max(j * dp[i - j], j * (i-j))
        //    ���� j = 1,2,...i-1 ���� dp[i] = max[ dp[i], max(j * dp[i - j], j * (i-j)) ]
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(
                dp[i], max(j*(i-j),j*dp[i-j])
            );
        }
    }

    // 5. �˹�ģ����֤
    //    ��
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size()-1];
}
