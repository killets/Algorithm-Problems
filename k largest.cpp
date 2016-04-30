http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

不要求sort。记住第k大的数，后面的数比它大就进去，把旧的第k数踢出来，得到新的第k大数，下一个数如果小，自己再看下一个。

建size=k minheap,这样最小，即第k大的数就在root，方便比较。

复杂度 o(k-构造， + （n-k）log(k)假设每个都进来heapfy)
