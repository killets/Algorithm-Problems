//别人的算法也非常有趣，值得学习，
//还是将数字看成3档，千，百，十，个
//然后组合字符，用于表示各个数字1～9
//这样应该更快

// this problem is similar to 10-digit-rule,
// 1000,900,500,...
// test every digit bit, add divdision to result string
// below is the basic algorithm, it may be accelerated in oberversation
// that after 1000,900, we can directly go to test 90

/*
Symbol	Value
I	1  --
V	5
X	10  --
L	50
C	100 --
D	500
M	1,000
Combination	Value
IV	4
IX	9
XL	40
XC	90
CD	400
CM	900
*/

class Solution {
public:
    string intToRoman(int num) {
        string result="";
        int d[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0; i<13;i++){
            while(num>=d[i]&&num>0){
                result+=s[i];
                num-=d[i];
            }
        }
  
    return result;
    }
};
