# my-cpp-leetcode
This is my C++ coding repository for solving LeetCode's problems.

## Attention

 1. 第 019 题是移除倒数第 `N` 个元素；而第 203 题是移除整数第 `N` 个元素。
 2. 第 349 题和第 350 题都是考察 Hash 表的基本操作的。
 3. 第 015 题自己写的算法 `solution1` 不好，修改了三次通过率也才 `98/313` 。
 4. **注意** ：第 015 题和第 018 题在《代码随想录》中属于哈比表下的内容，但是使用的是双指针法。
 5. 如果题目关键的部分直接用库函数就可以解决，建议不要使用库函数。毕竟面试官一定不是考察你对库函数的熟悉程度， 如果使用python和java 的同学更需要注意这一点，因为python、java提供的库函数十分丰富。如果库函数仅仅是 解题过程中的一小部分，并且你已经很清楚这个库函数的内部实现原理的话，可以考虑使用库函数。
 6. 



## Tutorial

 1. [C++ set 数据类型教学](https://www.programiz.com/cpp-programming/set)。
 2. [C++ vector 数据类型教学](https://www.programiz.com/cpp-programming/vectors)。


## Thoughts

 - Hash 表中的 `unordered_map<int, int>` 很像 `Python` 字典了，前面一个 `int` 表示键 (key) 而后面的 `int` 表示值 (value) 。
	因此第 350 题的 `count_map[i]++;` 或者 `count_map[j]--;` 都表示相当于 Python 语言中的检索键并对键对应的值做增减操作。

 - Hash 表中的 `vector<int>` 很像 `Python` 列表了：初始化、遍历以及增删改查等等。

 - Hash 表的一般思路总结。【1】存在两个对象，一个对象“充斥”某个 Hash 表，另一个对象“消耗”这个 Hash 表。求交集、求（有序的）公共子集都是这个思路。

 - 第 202 题目中说了会 **无限循环** ，那么也就是说求和的过程中，sum的结果可能会重复出现，这对解题很重要！

 - Carl:"首先我再强调一下 *什么时候使用哈希法* ，当我们需要 **查询一个元素是否出现过** ，或者 **一个元素是否在集合里的时候** ，就要第一时间想到哈希法。"

