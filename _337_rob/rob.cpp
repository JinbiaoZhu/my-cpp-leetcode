#include "rob.h"

int rob(treeNode* root)
{
	vector<int> result = robInTree(root);
	return max(result[0], result[1]);
}


// 1. ȷ���ݹ麯������ֵ���������
// 1. vector<int> {3 ,5} �±�Ϊ 0 ��¼��͵�ýڵ����õ��ĵ�����Ǯ
//                       �±�Ϊ 1 ��¼͵�ýڵ����õ��ĵ�����Ǯ��
vector<int> robInTree(treeNode* current) 
{
	// 2. ȷ���ݹ麯����ֹ����
	if (current == nullptr)
	{
		return vector<int> {0, 0};
	}

	// 3. ȷ��������������: ������� + ��̬�滮
	vector<int> left_result = robInTree(current->left);
	vector<int> right_result = robInTree(current->right);

	// 4. ��ǰ�ڵ�͵ + ���������ӽڵ㲻͵
	int val1 = current->nodeValue + left_result[0] + right_result[0];
	// 4. ��ǰ�ڵ㲻͵ + ���������ӽڵ�͵���ֵ, �����ӽڵ��͵�ɲ�͵
	int val2 = max(left_result[0], left_result[1]) + max(right_result[0], right_result[1]);

	return vector<int> {val2, val1};
}
