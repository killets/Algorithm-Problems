//别人算法，最高票那个好像没有用DP；然后，我简化后把其中的找上次出现的数的复杂度降低到O(1)
//总共就是DP,O(n)
//改进见comment

// 2. 在以上基础上优化，寻找上一次出现的位置，优化前是O(n)，
// 想到用hashmap来记录，进而用asic表做hashmap，直接读出上次出现位置，
// 如果在len[i-1]范围外（左边），则len[i]=len[i-1]+1;
// 如果在范围内，则len[i] = i-(hash[s[i]]+1)+1;

// dynamic programing
// key idea is that form a substring, it must include its left neighbor;
// so if s[i] is not repeated before, len[i] = len[i-1] +1;
// else find the position s[i] is repeated, len[i]= len[i-1]+1 - (k+1);
// by define default len[0]=1, it's the same formula as above.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int len[n] = {0};
        len[0] = 1;
        for(int i=1; i<n; i++) {
            int k=-1;
            for(int j= 0; j<len[i-1]; j++){ // find the re-happen position
                if(s[i-len[i-1]+j]==s[i]) {
                    k = j;    
                    break;
                }
            }
            
            //len[i] = k==-1 ? len[i-1]+1 : len[i-1]+1-(k+1);    
            len[i] =len[i-1]+1-(k+1);
        }
        
        int max = len[0]; // find max substr
        for(int i=0; i<n; i++){
            if(len[i]>max)
            max=len[i];
        }
        return max;
    }
};
