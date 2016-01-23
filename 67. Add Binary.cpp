#include<iostream>
 #include<stack>
 #include<string>
 
using namespace std;

// add bit by bit, with carry on; digits into stack, then to string
class Solution {
public:
    string addBinary(string a, string b) {
        stack<bool> ans;
        bool carry = false;
        int m = a.length()-1;
        int n = b.length()-1;
        
        while(m>=0&&n>=0) {
            int tmp = a[m]-'0' +b[n]-'0' + carry; // formula
            if(tmp >=2){
                carry = true;
                tmp= tmp -2;
            }else{
                carry = false;
            }
            ans.push(tmp==1);
            m--;
            n--;
        }
        
        // a is longer
        while(m>=0) {
            int tmp = a[m]-'0' + carry;
            if(tmp >=2) {
                carry = true;
                tmp = tmp-2;
            }else{
                carry = false;
            }
            ans.push(tmp==1);
            m--;
        }
        
        // b is longer
        while(n>=0) {
            int tmp = b[n]-'0' + carry;
            if(tmp >=2) {
                carry = true;
                tmp = tmp -2;
            }else{
                carry = false;
            }
            ans.push(tmp==1);
            n--;
        }
        
        // if carry on
        if(carry)
        ans.push(true);
        
        // translate stack into string
        int k = ans.size();
        string result(k,'0');
        for(int i = 0; i<k; i++) {
            result[i]= ans.top()?'1':'0';
            ans.pop();
        }
        
        return result;
    }
};

int main() {
  Solution slu;
  cout<<slu.addBinary("11","11")<<endl;
}
