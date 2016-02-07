//别人算法写起来很简洁，感觉和我的naive的想法一样，就是逐个比较，我以为会超时，测试发现并没有，难道是因为写得很简短

//AC的代码是使用了双指针，套住一段然后比较，不匹配则移动到下一段
//string的搜索算法比如KMP等等未用到

// second, we can use two pointers, match head and tail, then compare entile substring
// if not equal, then move to next paired [head, tail] substring

// first try Naïve string search algorithm
// there are another algorithms, like Boyer–Moore string search algorithm, KMP 

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()) return -1;
        if(needle=="") return 0;
        int n = needle.length();
        int pos = 0;
        
        int start=0; 
        int right=0;
        
        while(pos+n-1<haystack.length()){
            if(haystack[pos]==needle[0] && haystack[pos+n-1]==needle[n-1]){
                if(haystack.compare(pos,n,needle)==0){
                    return pos;
                } else{
                    pos++;
                }
            } else{
                pos++;
            }
        }
        
        return -1;
    }


    int strStr1(string haystack, string needle) {
        if(needle.length()>haystack.length()) return -1;
        
        int start = 0;
        int pos = 0;
        int i = 0;
        while(i<needle.length()){ // substr
            if(haystack[pos]==needle[i]){
                if(i==0) // record start position of this loop
                    start=pos;
                pos++;
                i++;
                
            } else{
                if(i!=0){ // it has matched n[0]..., reset
                    i=0;
                    pos=start+1;
                } else{ //  not matched head
                    pos++;
                    if(pos>=haystack.length()){
                        return -1;
                }
            }
 
            }
        }
        
        return start;
    }
};
