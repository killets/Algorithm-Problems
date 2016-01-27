// 2: Time Limit Exceeded
// 
// 1: test start from i, next is (i+1)%n

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        for(int i=0; i<n; i++) {
            int sum=0;
            int cnt=0;
            for(int j=i; cnt<n; j=(j+1)%n, cnt++) {
                sum=sum+gas[j]-cost[j];
                if(sum<0)
                break;
            }
            if(sum>=0)
            return i;
        }
        return -1;
    }
};
