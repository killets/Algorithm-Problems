//由4sum看到，别人最快的答案思路和我是一样的，而且有些内层还没有去掉不等时重复的case的判断，但总体写得简洁
//值得研究


86题 Partion List中，关于linklist中设置dump假节点，可以简化问题

112 直接调用自身，而不去使用helper函数，简化写法

20 把合法情况列出来，然后其它都用 return false； 另外没有用case 而是if else if, 这样不写break，适合于较短的程序块，比如一句话。

132 Fewest palindrome partition（g4g）： track最小的方法，避免另外设置一个变量记录最小值，但要求c[][]的赋值代价不能比临时变量高
                // Make a cut at every possible localtion starting from i to j,
                // and get the minimum cost cut.
                C[i][j] = INT_MAX;
                for (k=i; k<=j-1; k++)
                    C[i][j] = min (C[i][j], C[i][k] + C[k+1][j]+1);
      常规写法是另外再设一个临时变量，最后赋给目标

Palindrome pair中 
http://unknown66.blogspot.com/2016/04/leetcode-336-palindrome-pairs.html
那个while(l<r) 很有意思
// -++++ --++++ ---+++ 我们常规的是判断两个substring. -和+同时判断 用for(int i=0; i<k; i++)
//用while之后 当r到达k时，l++；是先判断完-，再判断+

stl中的初始化要学会简化， todo
bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
