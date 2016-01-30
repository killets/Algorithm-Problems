//我写的完全是打补丁，这样的写法不严谨，容易出错

//wrong answer: "One Million  Thousand"

// wrong answer: " Twelve Thousand Three Hundred Forty Five" ((tmp<100)?"":" ")

// Wrong Answer :100000
// 直接string比vector快

//my idea is backforth, start from the right most bit
// 123, three twenty one hundred
// 113, three, -three, thirteen, hundred one
// 1123, three, twenty  ,hundred one, thounsand one 

// 2^31 is 2,147,483,648
// the answer is 648, then 483+ thousnd+648, then 147+million+before,
// finally delte the last space if exist

class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        
        string symbol[]={""," Thousand "," Million "," Billion "};
        string w[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
            "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"}; 
            
            
        string a[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        string ans="";
        //stack<string> vans;
        int s_cnt=0;
        while(num>0){
            int tmp=num%1000;
            //Key part
           string cur=(tmp/100>0? w[tmp/100]+" Hundred":"")+(tmp%100==0? "" : ((tmp<100)?"":" ")+ (tmp%100 <20? w[tmp%20]: a[tmp%100/10] + (tmp%10==0?"":" "+ w[tmp%10])));  //当整除时就没有后面部分了，小心多出空格
            //上面的式子太复杂难懂了，目的就是为了删除多余的0；
            ans = cur+ (cur==""?"":symbol[s_cnt])+ans; //wrong answer: "One Million  Thousand"
     
            // vans.push(symbol[s_cnt]);
            // vans.push(tmp%100 <20? w[tmp%20]:a[tmp%100/10] + (tmp%10?" "+ w[tmp%10]:""));
            // vans.push(tmp/100>0? w[tmp/100]+" Hundred":"");
            
            num = num/1000;
            s_cnt++;
        }
        // while(!vans.empty()){
        //     ans+=vans.top();
        //     ans+=" ";
        //     vans.pop();
        // }
        // return ans.substr(0,ans.length()-1);
    
        return ans[ans.length()-1]==' '?ans.substr(0,ans.length()-1): ans;
    }
};
