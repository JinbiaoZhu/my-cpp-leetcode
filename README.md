# my-cpp-leetcode
This is my C++ coding repository for solving LeetCode's problems.

## Attention

 1. 第 019 题是移除倒数第 `N` 个元素；而第 203 题是移除整数第 `N` 个元素。
 2. 第 349 题和第 350 题都是考察 Hash 表的基本操作的。
 3. 第 015 题自己写的算法 `solution1` 不好，修改了三次通过率也才 `98/313` 。
 4. **注意** ：第 015 题和第 018 题在《代码随想录》中属于哈比表下的内容，但是使用的是双指针法。
 5. 如果题目关键的部分直接用库函数就可以解决，建议不要使用库函数。毕竟面试官一定不是考察你对库函数的熟悉程度， 如果使用python和java 的同学更需要注意这一点，因为python、java提供的库函数十分丰富。如果库函数仅仅是 解题过程中的一小部分，并且你已经很清楚这个库函数的内部实现原理的话，可以考虑使用库函数。
 6. 第 701 题不能 “先递归遍历得到有序数组，将数值拆入到有序数组中，再重建二叉搜索树” 这是因为只有一个中序遍历不能重建整个二叉树，即使有 108 题可以重建的操作，但是重建的顺序很可能跟原来的不一致！
  7. 第 450 题为什么要进行 `delete root` 这样删除节点的操作？
   8. 从 2024 年 8 月 19 日开始采样 ACM 模式啦！因为笔试了两次发现 ACM 模式不过关。
        9. 第 2035 题没有做出来。

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

 - 字符串相关题目目前学习了两个方法：1. 宏观逆序 + 微观逆序；2. 字符数组逆序 + 双指针。

 - 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。

 - 优先级队列的定义

   ```c++
   priority_queue<pair<int, int>, vector<pair<int, int>>, myComparation> pri_que;
   ```

   这段代码定义了一个优先级队列（priority_queue），其元素类型为 `pair<int, int>` ，底层容器为 `vector<pair<int, int>>` ，并使用了自定义的比较函数 `myComparation` 来确定优先级。

   `priority_queue<pair<int, int>>` : `priority_queue` 是 C++ 标准库提供的一个模板类，用于实现优先级队列。 `<pair<int, int>>` 指定了优先级队列中存储的元素类型为 `pair<int, int>` ，即每个元素是一个由两个 `int` 类型组成的对（pair）。 `vector<pair<int, int>>` : 这是优先级队列底层存储元素的容器类型。 `vector<pair<int, int>>` 表示优先级队列将使用 `vector` 来存储其元素。`vector` 是一种动态数组，可以动态调整大小。 `myComparation` : 这是一个自定义的比较函数对象（也可以是一个函数指针或一个 lambda 表达式），用于确定优先级队列中元素的排序规则。 `myComparation` 必须实现一个返回布尔值的函数，接受两个 `pair<int, int>` 类型的参数，来比较它们的优先级。例如，如果 `myComparation(a, b)` 返回 `true` ，则在优先级队列中 `a` 的优先级高于 `b` 。

- 二叉树系列定义

  1. 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。

     若最底层为第 `h` 层（ `h` 从 1 开始），则该层包含 `1~2^(h-1)` 个节点。

  2. 优先级队列其实是一个堆，堆就是一棵完全二叉树，同时保证父子节点的顺序关系。

  3. 二叉搜索树是一个有序树。若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；它的左、右子树也分别为二叉排序树。

  4. 平衡二叉搜索树：又被称为 AVL（Adelson-Velsky and Landis）树，且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过 1 ，并且左右两个子树都是一棵平衡二叉树。

     C++ 中 `map` 、 `set` 、 `multimap` ， `multiset` 的底层实现都是平衡二叉搜索树，所以 `map` 、 `set` 的增删操作时间时间复杂度是 `logn` 。

- 用数组来存储二叉树如何遍历的呢？如果父节点的**数组下标**是 `i` ，那么它的左孩子就是 `i * 2 + 1` ，右孩子就是 `i * 2 + 2` 。

- 遍历顺序

  ```mermaid
  graph LR
  
  o(二叉树的遍历方式)
  o1(深度优先遍历)
  o2(广度优先遍历)
  o11(前序遍历)
  o12(中序遍历)
  o13(后序遍历)
  o21(层次遍历)
  o111(中间结点: 中左右)
  o112(方法: 递归法/迭代法)
  o121(中间结点: 左中右)
  o122(方法: 递归法/迭代法)
  o131(中间结点: 左右中)
  o132(方法: 递归法/迭代法)
  
  o --- o1
  o --- o2
  o1 --- o11
  o1 --- o12
  o1 --- o13
  o2 --- o21
  o11 --- o111
  o11 --- o112
  o12 --- o121
  o12 --- o122
  o13 --- o131
  o13 --- o132
  
  style o fill:black,stroke:black,stroke-width:1px,color:white
  style o1 fill:#f22816,stroke:#f22816,stroke-width:1px,color:white
  style o2 fill:#f2b807,stroke:#f2b807,stroke-width:1px,color:white
  style o11 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o12 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o13 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o21 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o111 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o112 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o121 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o122 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o131 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  style o132 fill:#fcd4d0,stroke:#fcd4d0,stroke-width:1px
  
  linkStyle 0 stroke:#f22816,stroke-width:8px;
  linkStyle 1 stroke:#f22816,stroke-width:8px;
  linkStyle 2 stroke:#f22816,stroke-width:5px;
  linkStyle 3 stroke:#f22816,stroke-width:5px;
  linkStyle 4 stroke:#f22816,stroke-width:5px;
  linkStyle 5 stroke:#f22816,stroke-width:5px;
  linkStyle 6 stroke:#f22816,stroke-width:2px;
  linkStyle 7 stroke:#f22816,stroke-width:2px;
  linkStyle 8 stroke:#f22816,stroke-width:2px;
  linkStyle 9 stroke:#f22816,stroke-width:2px;
  linkStyle 10 stroke:#f22816,stroke-width:2px;
  linkStyle 11 stroke:#f22816,stroke-width:2px;
  ```

- 使用递归函数遍历二叉树，什么时候不需要返回值？这里总结如下三点：

  如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。

  如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。

  如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。

- 二叉搜索树是一个有序树：

  若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；

  若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；

  它的左、右子树也分别为二叉搜索树；
  
  中序遍历下，输出的二叉搜索树节点的数值是有序序列。
  
  二叉搜索树也可以为空！
  
- 回溯法，一般可以解决如下几种问题。组合问题： `N` 个数里面按一定规则找出 `k` 个数的集合；切割问题：一个字符串按一定规则有几种切割方式；子集问题：一个 `N`  个数的集合里有多少符合条件的子集；排列问题： `N` 个数按一定规则全排列，有几种排列方式；棋盘问题： `N` 皇后，解数独等等；

- **回溯法解决的问题都可以抽象为树形结构：因为回溯法解决的都是在集合中递归查找子集，集合的大小就构成了树的宽度，递归的深度就构成了树的深度**。

  递归就要有终止条件，所以必然是一棵高度有限的树（N叉树）。

  ```reStructuredText
  void backtracking(参数) {
      if (终止条件) {
          存放结果;
          return;
      }
  
      for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
          处理节点;
          backtracking(路径，选择列表); // 递归
          回溯，撤销处理结果
      }
  }
  ```

- 动态规划问题 —— 01背包问题的基本迭代公式：

  **不放物品i**：由 `dp[i - 1][j]` 推出，即背包容量为 `j` ，里面不放物品 `i` 的最大价值，此时 `dp[i][j]` 就是 `dp[i - 1][j]` 。**放物品i**：由 `dp[i - 1][j - weight[i]]` 推出， `dp[i - 1][j - weight[i]]` 为背包容量为 `j - weight[i]` 的时候不放物品i的最大价值，那么 `dp[i - 1][j - weight[i]] + value[i]` （物品 `i` 的价值），就是背包放物品 `i` 得到的最大价值。

  递归公式： `dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);`
  
- 动态规划问题 —— 背包问题的迭代公式

  > 1. 问能否能装满背包（或者最多装多少）：`dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);`
  > 2. 问装满背包有几种方法：`dp[j] += dp[j - nums[i]];`
  > 3. 问背包装满最大价值：`dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);`
  > 4. 问装满背包所有物品的最小个数：`dp[j] = min(dp[j - coins[i]] + 1, dp[j]);`

- 动态规划问题 —— 背包问题的迭代顺序

  二维 dp 数组 + 01背包 ——> 先遍历物品还是先遍历背包都是可以的，且第二层 for 循环是从小到大遍历

  一维 dp 数组 + 01背包 ——> 先遍历物品再遍历背包容量，且第二层 for 循环是从大到小遍历。

  一维 dp 数组 + 完全背包 + **求组合数** ——> **外层 for 循环遍历物品，内层 for 遍历背包** 。

  一维 dp 数组 + 完全背包 + **求排列数** ——> **外层 for 循环遍历背包，内层 for 遍历物品** 。



