// 下面的代码有错，请找出！
// 错误现象是n=3时，输出正确；n=5时，输出不正确，现象是输出短了，而且没有
// （）（）（）（）（）这种.
// 正解见comments；此方法跑出来结果很慢，只有4%

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
    bool check(vector<bool> in) {
        stack<bool> s;
        for(auto e: in) {
            if(e)
                s.push(true);a
            else{
                if(s.empty())
                    return false;
                else
                    s.pop();
            }
        }
        return true;
    }
    
    
    void helper(vector<bool>& p, vector<string>& result, int pos, int cnt){
         vector<bool> pp{1,0,1,0,1,0,1,0,0,1};
                if(pp==p)
                cout<<"Find target"<<endl;
        
        if(cnt==0){
            if(check(p)) {
               
                
                string found(p.size(),' ');
                for(int i=0; i<p.size(); i++){
                    found[i]= p[i] ? '(': ')';
                }
                result.push_back(found);
            }
            return;
        }
        
        for(int i=pos; i<p.size()&&cnt>0; i++){
            p[i]=1;
            helper(p,result,pos+1,cnt-1);
            p[i]=0;
        }
        
    }

};
