//别人算法很简短，没有显性写出a[n][m+n];

// m digits*n digits, so there are n times multiply, every time shift left 1 digit, then add all n rows into final result
// Note: remeber 2d arry initialization

// Note: 9133*0 = 0000, should be 0
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        if(m+n==0) return string();
        
        int a[n][m+n];
        for(int i=0; i<n;i++){
        for(int j=0; j<m+n;j++)
        a[i][j]=0;
        }
        
        for(int i= n-1; i>=0; i--){
            int carry = 0;
            for(int j=m-1; j>=0; j--) {
                int sum = 0; 
                sum +=(num1[j]-'0')*(num2[i]-'0');
                sum += carry;
                a[n-1-i][n-1-i+m-1-j] = sum %10;
                carry = sum/10;
            }
            a[n-1-i][n-1-i+m] = carry;
        }
        
        // sum all digits
        int carry2 = 0;
        string ans(m+n,'0');
        
        for(int i = 0; i<m+n; i++) {
            int tmp = 0;
            for(int j=0; j<n; j++) {
                tmp+=a[j][i];
            }
            tmp+=carry2;
            carry2 = tmp/10;
            ans[m+n-1-i] = char(tmp%10+'0');
        }
        
        for(int i=0; i<=m+n-2; i++)
        if(ans[i]!='0') return ans.substr(i);
        
        return ans.substr(m+n-1);
        
    }
};
