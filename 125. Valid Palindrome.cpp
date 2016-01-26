// 别人算法简短clean，在于使用了库函数int isalnum ( int c );判断是否是字母或数字，
// int toupper ( int c );转换为大写if c is a lower case alpha

// 好多special case，wrong answer的结果有“!!!”, "0P", "ab2a"

// fixed wrong answer, input="b2"
// fixed in case input="!!!", while loop exceed string

// two pointers, skip non-alphanumeric char, then compare left, right char,if not equal
// return false, otherwise continue till left and right meet, return true

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            // Note fix input"!!!", should forbid pointers not exceed string
            //skip non alphanumeric char
            while(( ('a'<=s[left]&&s[left]<='z') ||('A'<=s[left]&&s[left]<='Z') ||('0'<=s[left]&&s[left]<='9'))==false && left<right) {
                left++;
            }
            while(( ('a'<=s[right]&&s[right]<='z') ||('A'<=s[right]&&s[right]<='Z') ||('0'<=s[right]&&s[right]<='9'))==false && left<right) {
                right--;
            }
            
            // compare as small format
            char x= s[left]<'A' ? s[left] : s[left]<'a' ? char(s[left]+'a'-'A') : s[left];
            char y= s[right]<'A' ? s[right] : s[right]<'a' ? char(s[right]+'a'-'A') : s[right];
            
            if(x!=y)
            return false;
            
            //update pointer
            left++;
            right--;
        }
        return true;
    }
};
