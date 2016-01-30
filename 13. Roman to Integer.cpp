//别人算法是倒着看，不是遇到I看看后面有没有V,X，而是逆序看，遇到数，看看
//这个数是不是比后一位刚看过的数小，如果小，比如I比V小，则I应该是-1，而不是+1；
//大的话就是+;这样好处在于没有那么多case要列出来。也是O(k),我感觉这还要慢些
//因为遇到V,L,D,M是不需要朝后看的。而且他还用了map。

// 所以，这样的问题有两类解法，顺着和倒着。

// this problem is to split string according to the rules of 
// roman numerber,special case like IV =4 instead of 1+5=6; 
// O(k)

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
    int romanToInt(string s) {
        int sum=0;
        for(int i=0; i<s.length();i++){
            switch(s[i]) {
                case 'I':  {
                    if(i+1<s.length()){
                        if(s[i+1]=='V'){ //IV
                        sum+=4;
                        i++;    
                        }
                        else if(s[i+1]=='X') { //IX
                            sum+=9;
                            i++;
                        }else{
                            sum+=1;
                        }
                    }else{
                        sum+=1;
                    }
                    break;
                }
                case 'X':  {
                    if(i+1<s.length()){
                        if(s[i+1]=='L'){ //XL
                        sum+=40;
                        i++;    
                        }
                        else if(s[i+1]=='C') {//XC
                            sum+=90;
                            i++;
                        }else{
                            sum+=10;
                        }
                    }else{
                        sum+=10;
                    }
                    break;
                }                
                 case 'C':  {
                    if(i+1<s.length()){
                        if(s[i+1]=='D'){ //CD
                        sum+=400;
                        i++;    
                        }
                        else if(s[i+1]=='M') {//CM
                            sum+=900;
                            i++;
                        }else{
                            sum+=100;
                        }
                    }else{
                        sum+=100;
                    }
                    break;
                }
                
                case 'V':
                    sum+=5;
                    break;
                case 'L':
                    sum+=50;
                    break;
                case 'D':
                    sum+=500;
                    break;
                case 'M':
                    sum+=1000;
                    break;
            }
            
        }
        
     return sum;
    }
};
