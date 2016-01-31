//别人的算法聪明在分档处理，先判断数的范围，那么格式就定了
//格式对应的判断条件就简化了，而且还使用recursive的方法，大数调用小数
//还有很巧妙的是开头一定有个space，然后返回substr(1);

// 重新组合逻辑，helper打印3位数以内的数
// wrong answer: "One Million  Thousand"
// wrong answer: " Twelve Thousand Three Hundred Forty Five" ((tmp<100)?"":" ")
// Wrong Answer :100000

#include<iostream>
 #include<string>
 #include<vector>
 #include<cfloat>
 #include<climits>
 
using namespace std;
class Solution {
public:
static const string symbol[4];
static const string uints[20];
static const string tens[10];
    //print 3-digits number 0<tmp<1000;
    string helper(int tmp) {
        string d[3]={"","",""};
        d[0] = tmp>=100?uints[tmp/100]+" Hundred":"";
        // also works below:
        //d[1] = tmp%10==0?tens[tmp%100/10]: (tmp%100<20?uints[tmp%100]:tens[tmp%100/10]+" "+uints[tmp%10]);
        d[1] = tmp%100<20 ? uints[tmp%100] : (tens[tmp%100/10]+ ((tmp%10)?" ":"") + uints[tmp%10]);
        return (d[0]!=""&&d[1]!="")?d[0]+" "+d[1]: d[0]+d[1];
    }
        
    
    string numberToWords(int num) {
       if(num==0) return "Zero";
       string ans="";
       int s_cnt=0;
       while(num>0) {
        int tmp=num%1000;
        string cur = helper(tmp);
        
        //only when there is a value and not the base place, we need add " " + symbol
        if(cur!=""&&s_cnt!=0)   
        cur=cur+" "+symbol[s_cnt];  // num=1000, 120 :should no space at last place
   
        // if last ans and cur is not empty, we connect two parts using " "
       if(ans!=""&&cur!="")
       ans = cur +" "+ ans;
       else
       ans = cur+ans;

        /*  same effect as:
            ans = cur=="" ? ans : cur + (s_cnt?" ":"") + symbol[s_cnt] + (ans==""?"":" "+ans);
        */
        num=num/1000;
        s_cnt++;
        }
       return ans;
    }
};


const std::string Solution:: symbol[4]={"","Thousand","Million","Billion"};
const std::string Solution:: uints[20]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};  
const std::string Solution:: tens[10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

int main() {
Solution slu;
cout<<slu.helper(123)<<"."<<endl;
cout<<slu.helper(100)<<"."<<endl;
cout<<slu.helper(120)<<"."<<endl;
cout<<slu.helper(112)<<"."<<endl;
cout<<slu.helper(40)<<"."<<endl;
cout<<slu.helper(41)<<"."<<endl;
cout<<slu.helper(13)<<"."<<endl;
cout<<slu.helper(0)<<"."<<endl;
cout<<slu.helper(1)<<"."<<endl;
cout<<endl;

cout<<slu.numberToWords(12345)<<"."<<endl;
cout<<slu.numberToWords(100000)<<"."<<endl;
cout<<slu.numberToWords(1000000)<<"."<<endl;
cout<<slu.numberToWords(1000012)<<"."<<endl;
cout<<slu.numberToWords(1200)<<"."<<endl;
cout<<slu.numberToWords(1120)<<"."<<endl;
cout<<slu.numberToWords(1001)<<"."<<endl;

}
