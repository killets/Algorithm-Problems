// 别人算法思想也差不多都是DP，细节处理不同，但似乎他们的写法规避了很多special case
// 我写的尝试了多次，才解决了其中有0这个问题
// Wrong Answer "10" "20" "110"
// 如果是当前是0，只能和前面组成10或20才有效
// Wrong Answer Input:"0" Output should be 0, not 1

// 有左右关系，很典型的DP问题
// "1212121" 观察到依次是1，2，3，5，8，13，21，fibonacci number
// 加入一个数，要么能和前面一个数组成新code，要么不能
// 如果能，则  （），tail-x 是一种组合，（，tail) +x是另一种组合，所以总数Dn= Dn-2+ Dn-1;
// 如果不能，则只有（，tail）+x这一种组合，总数Dn= Dn-1


class Solution {
public:
    int numDecodings(string s) {
        if(s==""||s[0]=='0') return 0;
        vector<int> D(s.length()+1);
        D[0]=1; // so can achieve D[2] = 1+1=2
        D[1]=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]=='0'){
                if(s[i-1]>'2'||s[i-1]=='0') // NOTE
                return 0;
                else
                D[i+1] = D[i-1]; // NOTE
            } else{
            
                if(s[i-1]=='2'&&s[i]>'6' || s[i-1]>'2' ||s[i-1]=='0'){ //can not combain, such as "27", "31", "30"，"02"
                    D[i+1]=D[i];
                }else
                    D[i+1]=D[i]+D[i-1];
            }
            
        }
        
        return D[s.length()];
    }
};
