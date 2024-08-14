## C++ 语言中用于写题解的固定代码结构

### Part 1. `vectotr` 容器 

1. 向量容器 `vector<int> nums;` 在第 `i` 个位置中插入某个元素 `j` 

   ```c++
   nums.insert(nums.begin() + i, j);
   ```

2. 向量容器 `vector<int> nums;` 按照某个顺序 `logic` 排序

   ```C++
   #include<algorithm>
   
   // ...
   sort(nums.begin(), nums.end(), logic);
   // ...
   
   static bool compare(const vector<int>& a, const vector<int>& b)
   {
       // YOUR LOGIC IS HERE
   }
   ```

   当 `sort` 函数中没有输入进 `logic` 函数名时，默认是升序/降序。

3. 