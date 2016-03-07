//基本是最快了，别人算法一样用stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string & e: tokens){
                if(e=="+"){
                    int right = s.top(); s.pop();
                    int left = s.top(); s.pop();
                    s.push(left+right);
                } else if(e=="-") {
                     int right = s.top(); s.pop();
                    int left = s.top(); s.pop();
                    s.push(left-right);
                } else if(e=="*") {
                     int right = s.top(); s.pop();
                    int left = s.top(); s.pop();
                    s.push(left*right);
                }
                else if(e=="/"){
                     int right = s.top(); s.pop();
                    int left = s.top(); s.pop();
                    s.push(left/right);
                } else{
                    s.push(std::stoi(e));
                }
        }
        return s.top();
    }
};

//非常慢，倒数0.几，怀疑是try这个太多了
//stack
//std::stoi
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string & e: tokens){
            try{
                s.push(std::stoi(e));    // if not valid number, will throw
            }
            catch (const std::invalid_argument& ia) {
                int right = s.top(); s.pop();
                int left = s.top(); s.pop();
                if(e=="+")
                    s.push(left+right);
                else if(e=="-")
                    s.push(left-right);
                else if(e=="*")
                    s.push(left*right);
                else
                    s.push(left/right);
            }
            
            catch(...)
                {cout<<"error"<<endl; return INT_MIN;}
        }
        
        return s.top();
    }
};
