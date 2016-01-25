// 注意两个指针要回退一步，算substr，而不能直接在len里面算，因为已经溢出了

// 4 之所以要两个loop搜索的原因是，回文有两种模式，奇数长1，3，5，7，和另一种偶数长2，4，6，8
// 感觉可以简化先搜奇数长，再看看延伸一边满足不偶数对称 (错误，行不通，只能解决aaaa这类，解决不了abba这类)

// 3: wrong answer, "iptmykvjanwiihepqhzupneckpzomgvzmyoybzfynybpfybngttozprjbupciuinpzryritfmyxyppxigitnemanreexcpwscvcwddnfjswgprabdggbgcillisyo" yoy "illi"
// cause is by in 2nd loop default cnt =2;
// change to use left right index to calculate length

// 2: wrong answer, ccb output c, should be cc
// loop index should be 0 to n-1; outbound is checked inside

// 1: I didn't find a clever way, my method is first find the mid-point of palindrome string
// from index =1 to n-2;
// then in every loop, do 2 times search, first time .||  second time |.|
// special case: aaa abbb aaaa xaaaax
// it's about O(n*n = n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<2) return s;
        //if(n==2) return s[0]==s[1]? s: s.substr(0,1);
        int max =0;
        string ans=s.substr(0,1);
        
        for(int i=0; i<n; i++) { // -*------------*- from 1 to n-2
            // even mode, aaaa, abba : ||
            if(s[i]==s[i+1]) {
                int left = i;
                int right = i+1;
                while(s[left]==s[right]&&left>=0&&right<=n-1) {
                    left--;
                    right++;
                }
                    //ans = s.substr(left, (right-1)-(left+1)+1);
                    left++;  // back a step
                    right--;
                    if(right-left+1>max) {
                         max = right-left +1;
                         ans = s.substr(left, max); 
                    }
               
            }
        
            // odd mode, aaa, aba : |*|
            if(s[i-1]==s[i+1]) {
                int left = i-1;
                int right = i+1;
                while(s[left]==s[right]&&left>=0&&right<=n-1) {
                    left--;
                    right++;
                }
                
                left++;  // back a step
                right--;
                if(right-left+1>max) {
                    max = right-left +1;
                    ans = s.substr(left, max); 
                }
            }
        }
        
        return ans;
    }
};

int main() {
Solution slu;
cout<<slu.longestPalindrome("a")<<endl;
cout<<slu.longestPalindrome("ab")<<endl;
cout<<slu.longestPalindrome("aa")<<endl;
cout<<slu.longestPalindrome("aaa")<<endl;
cout<<slu.longestPalindrome("abbb")<<endl;
cout<<slu.longestPalindrome("aaaa")<<endl;
cout<<slu.longestPalindrome("abba")<<endl;
cout<<slu.longestPalindrome("abcba")<<endl;
cout<<slu.longestPalindrome("abcddcba")<<endl;
cout<<slu.longestPalindrome("abcd")<<endl;
}
