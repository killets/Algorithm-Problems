//记前面的一个最小价，然后假设今天卖出，盈利是多少，和max比较，然后更新
//这个动态过程理解为卖出为第一天到最后一天都有可能，买入就为卖出前的最低即可
//然后算哪一天卖出有最高回报

//Time Limit Exceeded 

//为什么不是在最低价买入，最高价卖出？可能最低价出现在最高价之后.
// C(N取2),逐个比较不就是n^2吗？

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int minBuyPrice =INT_MAX;
        
        for(int i=0; i<prices.size(); ++i){
            int tmp = prices[i] - minBuyPrice;
            if(tmp>max)
                max = tmp;
            if(prices[i]<minBuyPrice)
                minBuyPrice = prices[i];
        }
        return max;
    }
};
