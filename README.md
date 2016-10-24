# TODO

[200题里程碑](https://drive.google.com/open?id=0B0BJAgFiD4jIeEpncFlYelZReFU)

[100题里程碑](https://drive.google.com/open?id=0B0BJAgFiD4jINXdJQkRoZE9nVlE)

效率可以高起来的，2～3小时5题，平时那是在磨洋工

Not very clear, need to re-study

* ~~134, gas station问题，最终解决了，是用的猜想方法来加速~~
* 94, 树的遍历的非递归算法，用stack存轨迹
* 15, 3SUM(2sum)时，two pointers的使用，双向移动
* 98, 类似树的中序遍历，存一个pre节点用于比较BST
* 130, Union-find
* 143, 属于“智力“题，考操作，算是我不太喜欢的题型
* 127, Word Ladder, 想破脑袋不会
* 114, 递归函数的理解和写法，实际运行栈图解分析
* 11, 双指针
* 137, 什么ones, twos, 模拟三进制

Multiple algorithms, need to re-study

* 22,
* 53, 很有意思，有助于理解DP
* 93, backtracking 和 DFS的关系?
* 55, 别人算法里面的逻辑？贪心而不是DP?
* 80, 最多允许存2次
* 28, 他们怎样使得code如此简洁?
* 15, 2sum::two pointers的使用，o(n^2)->o(n)
* 90, 组合问题中有重复元素，DP，backtracking, etc.
* 119,120, DP的bottom up简化了问题，并且注意倒序可避免旧值覆盖
* 139, DP的另一种写法，倒着推，和LinearPartion很像
* 114, DFS然后别人第一种写法递归很简洁，第二种方法非递归且空间为o(1)
* 112, backtracking在tree中的应用，mark
* 129, 非常好的一题，分治时注意看如何将上面的值朝下传

Note

* 2和67避免重复写代码，使用 while(l1||l2||carry)
* 121使用一个for动态记录前面的最小，并且计算当前的最大差值，很巧妙
* 39 combination用backtracking，条件不是cnt而是nums[i]<=target
* 14, 看起来复杂，但实质简单
* 300, DP思想扫除定势，返回值并不一定是dp[n]，比如此处需要遍历找max dp[i]
* 53, maxEndinghere的想法很好，和300一样，最终结果是dp过程中的最大值maxSofar,并且可优化空间
* 9, 学到的是要think from 抽象的层面，不要去利用最底层的特性作为算法，此谓”算法“。
* 35, 可以作为使用custom二分搜索的基础示例
* 156, 传值方式，一直到最低，然后组层上传，在传值的同时对这一层的结构做一些变换
* 361, 419联系起来，把左边和上边当墙，把左上角当做一段起点的标志，w是起点
* 378, 373 取出最小的然后放进去一个比它大的，这样k次得到k序列
* 333,366 后序访问 recursive倒着向上传值，传值的过程中还可以做其他事
* 386 树的方法，preorder，还有插入res中的顺序也很赞，一次到位
* ［思想］84，378, 373共同点是有种不变量的感觉，84题栈中前面的都比它小（大的都弹出去了），后面比它大，直到当前i也比它小，这样找到了两个边界
