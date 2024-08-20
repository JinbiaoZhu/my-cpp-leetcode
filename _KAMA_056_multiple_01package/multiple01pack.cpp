#include "multiple01pack.h"
#include"utils.h"

int multiple01pack(vector<int>& weights, vector<int>& values, vector<int>& nums, int capacity)
{
    int numType = weights.size();

    // 1. ȷ����̬�滮���� dp[i] ��ʾ������ i ����������ļ�ֵ�� dp[i]
    // 3. ȷ����̬�滮�����ʼ��, ȫ 0 ����
    vector<int> dp(capacity + 1, 0);

    // 4. ȷ����̬�滮�ı���˳��: ������Ʒ (����) �ٱ������� (����)
    for (int i = 0; i < numType; i++) 
    {
        for (int j = capacity; j >= weights[i]; j--)
        {
            for (int k = 1; k <= nums[i] && j - k * weights[i] >= 0; k++)
            {
                // 2. ȷ����̬�滮�ĵ��ƹ�ʽ: dp[i] = max(dp[i], dp[i - k * weights[j]] + k * values[j])
                dp[j] = max(dp[j], dp[j - k * weights[i]] + k * values[i]);
            }
        }
    }

    // 5. �˹�ģ����ֵ���
    print_vector(dp);

    return dp[capacity];
}
