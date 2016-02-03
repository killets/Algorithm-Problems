// 结果比较图 https://drive.google.com/open?id=0B0BJAgFiD4jIbzNneUQxNENodjQ
// version 4: change vector<bool> to string, 加快了很多很多，0ms， 34% 最快一档！说明直接string比vector快

// version 3: 继续加快，更新check函数，使用int的加减代替stack操作. 9%

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
        string p(2*n,')');
        p[0]='(';
        helper(p,result,1,n-1);
        return result;
    }
private:
    //check if a combination is well-formed 
    bool check(string in, int pos) {
       int sum=0;
        for(int i=0; i<pos; i++) {
            if(in[i]=='(')
                sum++;
            else{
                sum--;
                if(sum<0)
                return false;
            }
        }
        return true;
    }
    
    
    void helper(string & p, vector<string>& result, int pos, int cnt){
        /* //用来检查是否每个组合都能遍历到，下面那个错误就导致pp未能检查到
        vector<bool> pp{1,0,1,0,1,0,1,0,1,0};
         if(pp==p)
         cout<<"Find target"<<endl;*/
        
        if(!check(p, pos))
            return;
        
         if(cnt==0){
                 result.push_back(p);
            // }
             return;
         }
        
          int p_cnt = (p.length()/2)-cnt;
 //       for(int i=pos; i<=p.size()-cnt&&cnt>0&&pos<=p.size()-2*cnt; i++){//更新-cnt，反括号多了
          for(int i=pos; i <= 2*p_cnt && cnt>0; i++){//再更新，继续缩小
            p[i]='(';
            helper(p,result,i+1,cnt-1); //Note!!!!!!!!!!!!!!害我检查了两个小时!!!!!!!!!!!!!!!!!!
            p[i]=')';   //不是pos+1;
        }
    }

};
