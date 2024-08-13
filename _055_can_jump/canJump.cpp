#include "canJump.h"

bool canJump(vector<int>& nums)
{
	int current_max_range = 0;
	int predict_range = 0;

	for (int i = 0; i <= current_max_range; i++)
	{
		predict_range = i + nums[i];  // ��¼��ǰ״̬�¿ɴ�����״̬
		current_max_range = max(predict_range, current_max_range);  // ��Ҫ��ʵ�ʵıȽ�
		if (current_max_range>=nums.size()-1)
		{
			return true;
		}
	}
	return false;
}
