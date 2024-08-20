#include "numSquares.h"
#include"utils.h"
#include"vector"

using namespace std;

int numSquares(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int bagSize = n;
    int numType = n;
    vector<int> nums(numType, 0);
    for (int i = 0; i < numType; i++)
    {
        nums[i] = i * i;
    }

    // 1. ȷ����̬�滮���� dp[i] ��ʾĿ����ֵΪ i �����µ���ȫƽ���������� dp[i]
    vector<int> dp(bagSize + 1, 0);

    // 3. ȷ����̬�滮��ʼ��: dp[0] = 0; dp[i] = 100000000 ������Ŀ�е����ֵ��
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = 100000000;
    }

    // 4. ȷ����̬�滮�ı�����ʽ: ����ֵ����, �ٱ���ƽ����
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < numType; j++)
        {
            if (i -j*j>=0 && dp[i-j*j]<=100000000)
            {
                // 2. ȷ����̬�滮���ƹ�ʽ: dp[i] = min( dp[i], dp[i-j*j]+1 )
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
        }
    }

    // 5. �˹�������ֵģ��
    print_vector(dp);

    return dp[bagSize];
}
