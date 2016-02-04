// 和别人算法一致，利用一个stack，遇到右符号就pop看是否匹配，最后看stack是否为空
// Wrong Answer, input "((", test stack empty or not
// Wrong Answer, input "[", so test length of string, odd:false 

// same idea from 22. Generate Parentheses, use one stack
class Solution {
public:
    bool isValid(string s) {
        stack<char> test;
        for(auto e: s){
            switch(e){
                case '(':
                case '{':
                case '[':
                    test.push(e);
                    break;
                case ')':
                    if(test.empty()||test.top()!='(')
                        return false;
                    else
                        test.pop();
                    break;
                case '}':
                    if(test.empty()||test.top()!='{')
                        return false;
                    else
                        test.pop();
                    break;   
                case ']':
                    if(test.empty()||test.top()!='[')
                        return false;
                    else
                        test.pop();
                    break;
            }
        }
        return test.empty(); // fix wrong answer, input "["
    }
};
