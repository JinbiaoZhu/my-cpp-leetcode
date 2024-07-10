## 栈和队列基础知识

[参考链接](https://programmercarl.com/%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)

栈提供 `push` 和 `pop` 等等接口，所有元素必须符合 **先进后出** 规则，所以栈<u>不提供走访功能</u>，也<u>不提供迭代器</u> (iterator) 。 不像是 `set` 或者 `map` 提供迭代器 `iterator` 来遍历所有元素。

![](https://code-thinking-1253855093.file.myqcloud.com/pics/20210104235459376.png)

栈的内部结构，栈的底层实现可以是 `vector` , `deque` 和  `list` ， 主要就是数组和链表的底层实现。

**常用的 `SGI STL` ，如果没有指定底层实现的话，默认是以 `deque` 为缺省情况下栈的底层结构。**

`deque` 是一个双向队列，只要封住一段，只开通另一端就可以实现栈的逻辑了。

**`SGI STL` 中 队列底层实现缺省情况下一样使用 `deque` 实现的。**

可以指定 `vector` 为栈的底层实现，初始化语句如下：

```cpp
std::stack<int, std::vector<int> > third;  // 使用vector为底层容器的栈
```

刚刚讲过栈的特性，对应的队列的情况是一样的。

队列中先进先出的数据结构，同样不允许有遍历行为，不提供迭代器， **`SGI STL` 中队列一样是以 `deque` 为缺省情况下的底部结构。**

也可以指定 `list` 为起底层实现，初始化 `queue` 的语句如下：

```cpp
std::queue<int, std::list<int>> third; // 定义以list为底层容器的队列
```

所以 `STL` 队列也不被归类为容器，而被归类为 `container adapter` (容器适配器) 。

