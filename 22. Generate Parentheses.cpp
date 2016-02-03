// version 2: 继续加快，不等到最后才去检查是否合法，如果不合法直接退出, check增加pos参数
// 还是6 %

//很慢，除了55行更改之外，还可以提前结束，减少不可能的比较，当")"比(多时，提前结束
// 已经使用的(个数：p.size()/2 - cnt，（和）总数i
// i -(p.size()/2 -cnt) <= (p.size()/2-cnt) 
// 6%

// there are two roads to solve this problem,
// first is to generate all combinations then check if it's valid
// second is to follow some rules to build only valid patterns
// let's first try the 1st one

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<bool> p(2*n);
        p[0]=1;
        helper(p,result,1,n-1);
        return result;
    }
private:
    //check if a combination is well-formed 
    bool check(vector<bool> in, int pos) {
        stack<bool> s;
        for(int i=0; i<pos; i++) {
            if(in[i])
                s.push(true);
            else{//遇到反括号，就找正括号匹配，没有就报错
                if(s.empty())
                    return false;
                else
                    s.pop();
            }
        }
        return true;
    }
    
    
    void helper(vector<bool>& p, vector<string>& result, int pos, int cnt){
        /* //用来检查是否每个组合都能遍历到，下面那个错误就导致pp未能检查到
        vector<bool> pp{1,0,1,0,1,0,1,0,1,0};
         if(pp==p)
         cout<<"Find target"<<endl;*/
        
        if(!check(p, pos))
            return;
        
         if(cnt==0){
             //if(check(p)) {
                 string found(p.size(),' ');
                 for(int i=0; i<p.size(); i++){
                     found[i]= p[i] ? '(': ')';
                 }
                 result.push_back(found);
            // }
             return;
         }
        
          int p_cnt = (p.size()/2)-cnt;
 //       for(int i=pos; i<=p.size()-cnt&&cnt>0&&pos<=p.size()-2*cnt; i++){//更新-cnt，反括号多了
          for(int i=pos; i <= 2*p_cnt && cnt>0; i++){//再更新，继续缩小
            p[i]=1;
            helper(p,result,i+1,cnt-1); //Note!!!!!!!!!!!!!!害我检查了两个小时!!!!!!!!!!!!!!!!!!
            p[i]=0;   //不是pos+1;
        }
    }

};
