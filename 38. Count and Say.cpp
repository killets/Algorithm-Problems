//别人算法差不多，不过他们是直接用string存结果；分析见line 10
// 题目意思理解见comment

// my idea is every time input is last time's result, and we count the contend of an input vector,
// and record the result into another output vector, so we need two vectors: s(input), out
// for every count loop, we count the same char, if meet a different char, we put lastest cnt and 
// last char into out; also if when we reach the end of input, we put cnt and tmp into out.
// for parameter n, we do n-1 such loops. out is the result.

//跑到100就超时了；30的时候结果就很长了，说明复杂度还是挺高的。（n*k）
//这个里面我用数组的原因是，http://www.careercup.com/question?id=4425679 题目里面说有1个10，1个1
//（上一组是10个1），那1个10，10这个数存成字符就成了1个1，1个0了，所以为了不拆分就用vector<int>来存；
// 负面影响就是vector.clear()以及push比字符操作可能要慢一点

class Solution {
public:
    string countAndSay(int n) {
        vector<int> out{1};
        for(int i=0; i<n-1; i++) {
            vector<int> s=out;
            out.clear();
            int cnt=0;
            int tmp=s[0]; 
            for(int j=0; j<s.size(); j++) {
                if(s[j]==tmp)
                    cnt++;
                else{
                    out.push_back(cnt);
                    out.push_back(tmp);
                    tmp = s[j];
                    cnt=1;
                }
            }
            out.push_back(cnt);
            out.push_back(tmp);           
        }
        string ans;
        for(auto e:out) {
            ans+=e+'0';
        }
        return ans;
    }
};
