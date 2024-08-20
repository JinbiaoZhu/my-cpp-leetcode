#include "climb.h"
#include"utils.h"

int climb(vector<int>& nums, int target)
{
    // 1. ȷ����̬�滮����: dp[i] ��ʾ¥���� i �׵������ dp[i] �������
    vector<int> dp(target + 1, 0);

    // 3. ȷ����̬�滮�ĳ�ʼ��: dp[0] = 1
    dp[0] = 1;

    // 4. ȷ����̬�滮�ı�����ʽ: ��¥�ݽ���������˳��
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
            {
                // 2. ȷ����̬�滮���ƹ�ʽ: dp[i] += dp[i-nums[j]]
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    
    // 5. �˹���ֵģ��
    print_vector(dp);

    return dp[target];
}
