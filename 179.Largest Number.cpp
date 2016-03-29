//好题，怎样想到的自己设计比较大小的函数！因为大数在前面都已经选定了，eg， 9， 6
//剩下的肯定是eg。 5， 56， 4，3， 这样肯定选56+5而不是5+56

//update: 再次测试别人时间用
//别人算法看起来很精简，但跑起来却是32ms？
//我和他的算法思想是一致的，不过我没有用strcmp(s1,s2)去比较，而是自己实现的strcmp。

//4 compare other's work, 4ms 100% vs ?
//3 change sort function, but still use return (s+t)>(t+s), 4ms, 100%, good enough, so not bother implement custom s+t>t+s 
//2 test auto & e :string vs auto e: string, 8ms, 93.3%, so no difference
//1 use simple custom sort function, works, 8ms, 93.3%

//综合最快，4ms有时8ms
class Solution {
private:
static bool customStringSort(string s, string t){
    const char * i = s.c_str();
    const char * j = t.c_str();
 
    while(*i==*j){
        i++; j++;
    }
    if(*i =='\0' &&  *j == '\0') return 0;
    else if(*i == '\0') return (s+t)>(t+s);
    else if(*j == '\0') return (s+t)>(t+s);
    else return *i>*j;
}

public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return string();
        vector<string> words;
        for(auto e: nums)
        words.push_back(to_string(e));
        sort(words.begin(),words.end(), &Solution::customStringSort); //区别在于自己实现strcmp()
        
        if(stoi(words[0])==0)
        return "0";
        
        string res;
        for(auto e: words){
            res+=e;
        }
        return res;
    }
};

//28ms, 32ms, VERY SLOW
class Solution_BIE_REN {
    public:
        string largestNumber(vector<int>& nums) {
            string ret;
            sort(nums.begin(),nums.end(),
                [](const int &m,const int&n){
                    return to_string(m)+to_string(n)>to_string(n)+to_string(m);});
            for(int i=0;i<nums.size();++i){
                ret+=to_string(nums[i]);
            }
            if(ret[0]=='0') //for the case nums are all zeros
                return "0";
            return ret;
        }  
    };
