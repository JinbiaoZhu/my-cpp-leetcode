# my-cpp-leetcode
This is my C++ coding repository for solving LeetCode's problems.

## Attention

 1. 第 019 题是移除倒数第 `N` 个元素；而第 203 题是移除整数第 `N` 个元素。
 2. 第 349 题和第 350 题都是考察 Hash 表的基本操作的。



## Tutorial

 1. [C++ set 数据类型教学](https://www.programiz.com/cpp-programming/set)。
 2. [C++ vector 数据类型教学](https://www.programiz.com/cpp-programming/vectors)。


## Thoughts

 - Hash 表中的 `unordered_map<int, int>` 很像 `Python` 字典了，前面一个 `int` 表示键 (key) 而后面的 `int` 表示值 (value) 。
	因此第 350 题的 `count_map[i]++;` 或者 `count_map[j]--;` 都表示相当于 Python 语言中的检索键并对键对应的值做增减操作。

 - Hash 表中的 `vector<int>` 很像 `Python` 列表了：初始化、遍历以及增删改查等等。

 - Hash 表的一般思路总结。【1】存在两个对象，一个对象“充斥”某个 Hash 表，另一个对象“消耗”这个 Hash 表。求交集、求（有序的）公共子集都是这个思路。

 - 第 202 题目中说了会 **无限循环** ，那么也就是说求和的过程中，sum的结果可能会重复出现，这对解题很重要！

