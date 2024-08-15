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

### Part 2. 字符串

1. 整型数 `n` 和字符串 `strNum` 的互转换（假设是可转换成字符串的整型数）。

   用的是 `to_string` 函数和 `stoi` 函数，要引用 `<string>` 头文件和添加 `std` 名命空间。

   ```c++
   #include<string>
   
   using namespace std;
   
   string strNum = to_string(n);
   int N = stoi(strNum);
   ```

2. 