#include "numTrees.h"
#include<vector>

using namespace std;

int numTrees(int n)
{
    // 1. ȷ����̬�滮��������±�: dp[i] ��ʾ i �������Բ��� dp[i] ������������
    vector<int> dp(n+1);

    // 3. ȷ����̬�滮�ĳ�ʼ��
    dp[0] = 1;

    // 2. ȷ����̬�滮�ĵ��Ʊ��ʽ
    for (int i = 1; i <= n; i++)
    {
        // 4. ȷ����̬�滮�ı�����ʽ: ��ǰ���, �������ұ���
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j-1] * dp[i - j];
        }
    }
   
    // 5. ȷ���˹���ֵģ��
    //    ʡ��
    return dp[n];
}
