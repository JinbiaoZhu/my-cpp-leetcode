// 20240907_meituan_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s_input;
    cin >> s_input;
    int size = s_input.size();

    for (int i = 0; i < size; i++)
    {
        if (s_input[i] == 'Q') { s_input[i] = 'P'; continue; 
        }
        if (s_input[i] == 'W') { s_input[i] = 'O'; continue; 
        }
        if (s_input[i] == 'E') { s_input[i] = 'I'; continue; 
        }
        if (s_input[i] == 'R') { s_input[i] = 'U'; continue;
        }
        if (s_input[i] == 'T') { s_input[i] = 'Y'; continue;
        }
        if (s_input[i] == 'P') { s_input[i] = 'Q'; continue;
        }
        if (s_input[i] == 'O') { s_input[i] = 'W'; continue;
        }
        if (s_input[i] == 'I') { s_input[i] = 'E'; continue;
        }
        if (s_input[i] == 'U') { s_input[i] = 'R'; continue;
        }
        if (s_input[i] == 'Y') { s_input[i] = 'T'; continue;
        }

        if (s_input[i] == 'A') { s_input[i] = 'L'; continue;
        }
        if (s_input[i] == 'S') { s_input[i] = 'K'; continue;
        }
        if (s_input[i] == 'D') { s_input[i] = 'J'; continue;
        }
        if (s_input[i] == 'F') { s_input[i] = 'H'; continue;
        }
        if (s_input[i] == 'G') { s_input[i] = 'G'; continue;
        }
        if (s_input[i] == 'H') { s_input[i] = 'F'; continue;
        }
        if (s_input[i] == 'J') { s_input[i] = 'D'; continue;
        }
        if (s_input[i] == 'K') { s_input[i] = 'S'; continue;
        }
        if (s_input[i] == 'L') { s_input[i] = 'A'; continue;
        }

        if (s_input[i] == 'Z') { s_input[i] = 'M'; continue;
        }
        if (s_input[i] == 'X') { s_input[i] = 'N'; continue;
        }
        if (s_input[i] == 'C') { s_input[i] = 'B'; continue;
        }
        if (s_input[i] == 'V') { s_input[i] = 'V'; continue;
        }
        if (s_input[i] == 'B') { s_input[i] = 'C'; continue;
        }
        if (s_input[i] == 'N') { s_input[i] = 'X'; continue;
        }
        if (s_input[i] == 'M') { s_input[i] = 'Z'; continue;
        }
    }

    
    cout << s_input << endl;
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
