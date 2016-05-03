First we post the code here.

int maxProfit(vector<int> &prices) {
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p) 
      ret += max(prices[p] - prices[p - 1], 0);    
    return ret;
}
Second, suppose the first sequence is "a <= b <= c <= d", the profit is "d - a = (b - a) + (c - b) + (d - c)" without a doubt.
And suppose another one is "a <= b >= b' <= c <= d", the profit is not difficult to be figured out as "(b - a) + (d - b')". So you just target at monotone sequences.

相似得
public class Solution {
public int maxProfit(int[] prices) {
    int total = 0;
    for (int i=0; i< prices.length-1; i++) {
        if (prices[i+1]>prices[i]) total += prices[i+1]-prices[i];
    }

    return total;
}

这种写法比geeksforgeeks中找局部最小和局部最大要简单得多；
http://www.geeksforgeeks.org/stock-buy-sell/
