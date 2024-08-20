#include "rob.h"
#include"utils.h"

int rob(vector<int>& nums)
{
    int N = nums.size();

    // 1. ȷ����̬�滮���� dp[i] ��ʾ�ڵ� 1 ���� i �������п���͵���������
    vector<int> dp(N, 0);

    if (N==1)
    {
        return nums[0];
    }
    else
    {
        // 3. ȷ����̬�滮�����ʼ��: dp[0] = nums[0]; dp[1] = max(nums[0],nums[1])
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        // 4. ȷ����̬�滮����˳��: �������Ҵ�С�������
        for (int i = 2; i < N; i++)
        {
            // 2. ȷ����̬�滮���ƹ�ʽ: dp[i] = max(
            //     dp[i-1] ----> ˵�� dp[i-1] ��͵����, ��Ҳ�����͵��
            //     dp[i-2] + nums[i] ----> ˵�� dp[i-2] ��͵����, ��ҿ��Խ���͵   
            // )
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 5. �˹�ģ����ֵ���
        print_vector(dp);

        return dp[N - 1];
    }
}
