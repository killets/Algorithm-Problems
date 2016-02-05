//别人算法是顺着，当遇到非space时++，遇到space就归0;
// 我觉得也很好，但是倒着的好处在于假如句子很长，并且很多词，那题目问的是lastword，所以倒着读
// 可以避免读一开始的很长一段无用的内容

//一开始漏掉了 "Hello World "的情况
// test: “Hello world” "he wd " " h   " " h  w d " "    "

// back pointer
// find first space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i= s.length()-1;
        while(s[i]==' '&&i>=0) //skip tail spaces
        i--;
        if(i==-1) return 0;

        int start=i+1;
        while(s[i]!=' '&&i>=0){ //find first space or exceed string
            i--;
        }
        
        return start-i-1;
    }
};
