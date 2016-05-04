连续非负数subarray
见http://www.geeksforgeeks.org/find-subarray-with-given-sum/
基本方法是遍历从每个元素出发的subarray，超过sum之后就break；
改进方法是一直加下去，直到超过sum则不停的将开头元素去掉，因为这一步实际上是检查了那个start开头的子串的可能性，现在已经不可能了；
然后再判断，不够就继续右扩。 这样每个元素最多访问两次，加一次，减一次。
复杂度O(n)
