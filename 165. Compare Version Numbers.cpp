// 别人算法在于在format的过程中即开始比较，相同才朝下进行转换
// 我也想到了这样会快些，不过还是单独写了函数

// 3 Note: for(..; condition 1 && condition 2; ..)
// 2 1's idea is wrong, 1.10 means 10th after 1, while 1.1 means 1th after 1

// 1 idea: convert string to float number, then compare number
// sum= sum*10+cur; for integer part; 
// sum+= cur*(0.1^n);

class Solution {
public:
    float string2num(string s){
        float b=1;
        bool dig=false;
        float sum=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='.'){
                dig=true;
                continue;
            }
            if(dig){
                b*=0.1;
                sum += (s[i]-'0')*b;
            }else{
                sum = sum*10+(s[i]-'0');
            }
        }
        return sum;
    }
    
    vector<int> string2ver(string s){
        vector<int>ans;
        int sum=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='.'){
                ans.push_back(sum);
                sum=0;
                continue;
            }
            sum=sum*10+s[i]-'0';
        }
        ans.push_back(sum);
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = string2ver(version1);
        vector<int> v2 = string2ver(version2);
        int i, j;
        // compare same length part
        for(i=0, j=0; i<v1.size()&&j<v2.size(); i++, j++)
        if(v1[i]<v2[i])
            return -1;
        else if(v1[i]>v2[i])
        return 1;
        // if v1 is longer, return if it has non-zero version
        while(i<v1.size()) {
            if(v1[i]!=0)
                return 1;
            i++;
        }
        // if v2 is longer
        while(j<v2.size()) {
            if(v2[j]!=0)
                return -1;
            j++;
        }
        return 0;
    }
};
