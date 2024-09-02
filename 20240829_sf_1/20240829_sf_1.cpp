// 20240829_sf_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

//void judgeName(string& str) 
//{
//    // 针对 MyLastName
//    if ('A' <= str[0] <= 'Z')
//    {
//        cout << "indistinct" << endl;
//    }
//
//    // 接下来部分都是首字母小写的, 采用双指针
//    for (int index = 0; index < str.size() - 1; index+=2)
//    {
//        // case 1. 前字母小写, 后字母小写
//        if ('a' <= str[index] <= 'z' && 'a' <= str[index + 1] <= 'z')
//        {
//            continue;
//        }
//
//        // case 2. 前字母小写, 后字母大写
//        if ('a' <= str[index] <= 'z' && 'A' <= str[index + 1] <= 'Z')
//        {
//            // 先把大写改成小写
//            str[index + 1] = char(str[index + 1] - 32);
//            // 再在字母前面增加一个下划线
//            str.insert(str.begin() + index + 1, '_');
//        }
//
//        // case 3. 前字母小写, 后是下划线
//        if ('a' <= str[index] <= 'z' && str[index + 1] == '_')
//        {
//            // case 3.1 如果是末尾则输出
//            if (index + 1 == str.size() - 1)
//            {
//                cout << "indistinct" << endl;
//                break;
//            }
//
//            // case 3.2 如果下一个还是下划线
//            if (str[index + 2] == '_')
//            {
//                cout << "indistinct" << endl;
//                break;
//            }
//
//        }
//
//    }
//
//
//}

void judgeName(string& name) 
{
    for (int index = 0; index < name.size(); index++)
    {
        if ('a' <= name[index] && name[index] <= 'z')
        {
            continue;
        }
        else
        {
            if ('A' <= name[index] && name[index] <= 'Z')
            {
                if (index == 0)
                {
                    cout << "indistinct" << endl;
                    return;
                }
                else if ('a' <= name[index - 1] && name[index - 1] <= 'z' && 'a' <= name[index + 1] && name[index + 1] <= 'z')
                {
                    name[index] = char(name[index] + 32);
                    name.insert(name.begin() + index, '_');
                    continue;
                }
                else
                {
                    cout << "indistinct" << endl;
                    return;
                }
            }
            else if (name[index] == '_')
            {
                if (index == name.size() - 1)
                {
                    cout << "indistinct" << endl;
                    return;
                }
                else if ('a' <= name[index - 1] && name[index - 1] <= 'z' && 'a' <= name[index + 1] && name[index + 1] <= 'z')
                {
                    continue;
                }
                else
                {
                    cout << "indistinct" << endl;
                    return;
                }
            }
            else
            {
                cout << "indistinct" << endl;
                return;
            }
        }
    }

    cout << name << endl;
    return;
}


int main()
{
    int N;
    cin >> N;

    vector<string> strList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> strList[i];
    }

    for (int i = 0; i < N; i++)
    {
        judgeName(strList[i]);
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
