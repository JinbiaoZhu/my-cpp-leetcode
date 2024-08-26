## C++ 语言中用于写题解的固定代码结构

### Part 1. `vectotr` 容器 

1. 向量容器 `vector<int> nums;` 在第 `i` 个位置中插入某个元素 `j` 

   ```c++
   nums.insert(nums.begin() + i, j);
   ```

2. 向量容器 `vector<int> nums;` 返回最后一个元素

   ```C++
   int value = nums[nums.size()-1];
   ```

3. 向量容器 `vector<int> nums;` 按照某个顺序 `logic` 排序

   ```C++
   #include<algorithm>
   
   // ...
   sort(nums.begin(), nums.end(), compare);
   // ...
   
   static bool compare(int a, int b)
   {
       // YOUR LOGIC IS HERE
       // return a > b
       // return b <= b
   }
   ```

   当 `sort` 函数中没有输入进 `logic` 函数名时，默认是 **升序** / **降序** 。
   
4. ACM 模式下容器的输入（以 01 背包问题为例）。

   ```C++
   // ...
   int n, bagweight;
   cin >> n >> bagweight;
   
   vector<int> weight(n, 0);  // 物体重量表格
   vector<int> value(n, 0);   // 物体价值表格
   
   for (int i = 0; i < n; ++i)
   {
       cin >> weight[i];
   }
   for (int i = 0; i < n; ++i)
   {
       cin >> value[i];
   }
   ```

### Part 2. `list` 容器

1. `list` 容器相当于 C++ 语言中内置的链表数据结构。

   定义、初始化和遍历如下代码所示：

   ```c++
   #inclue <list>
   
   using namespace std;
   
   vector<list<int>> graph(m+1);
   for (int i = 1; i <= m; i++)
   {
   	cin >> s >> t;
   	graph[s].push_back(t);
   }
   
   for (int i = 1; i < graph.size(); i++)
   {
   	for (int j : graph[i])
   	{
   		cout << j << " ";
   	}
   	cout << endl;
   }
   ```

### Part 3. 字符串

1. 整型数 `n` 和字符串 `strNum` 的互转换（假设是可转换成字符串的整型数）。

   用的是 `to_string` 函数和 `stoi` 函数，要引用 `<string>` 头文件和添加 `std` 名命空间。

   ```c++
   #include<string>
   
   using namespace std;
   
   string strNum = to_string(n);
   int N = stoi(strNum);
   ```

2. 