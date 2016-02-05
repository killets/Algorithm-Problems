// 别人算法思想跟我是一样的，也是基于把k分解成最近的factorial number，然后看最高位是哪个，接着算余下的个数
// 但是我写了好长时间。待分析总结。
// 算法思路图 https://drive.google.com/open?id=0B0BJAgFiD4jIRm5DbUlqUUZxcXM 

//这里分析出来n-firstDig和realFirstDig交叉了
//前者是1，后者是0；
// 应该分析MOD==0整除时的情况，这种情况也可以归类到上面的if（ans==k），对应改为(k%ans==0)
//但我直接加了if(k==0)返回最开始的那个数即倒序。

// oh my god, spend too much time to fix and tune small details of indexing and logic

// Time Limit Exceeded  Last executed input:8 8590

// based on 31. Next Permutation, we can call it k-1 times from input 1,2,..n
class Solution {
public:
    string getPermutation(int n, int k){
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        nums[i] =i+1;
        return helper(n, k, nums);
    }


    string helper(int n, int k, vector<int> nums) {
    string result="";
      if(k==0) { // also means MOD = 0; // TODO
          for(int i= nums.size()-1; i>=0; i--)
          result+='0'+nums[i];
          return result;
      }  
    
    int ans=1;
    int i=1;
    while((ans*=i) <= k){
        i++;
    }
 
    ans=ans/i;
    int firstDig=0;
    if(ans==k){
        firstDig=i-1;
        
        for(int i=1; i<n-(firstDig-1);i++)
        result+='0'+nums[i-1];
        
        for(int i=n; i>=n-(firstDig-1); i--)
        result+='0'+nums[i-1];
        
       return result;
        
    } else {
        firstDig = i; // i-1 digits are all used!
        int FD = k / ans; 
        int MOD = k%ans;
        int FD1 = MOD==0? FD: FD+1;
        
        int realFirstDig =  n-firstDig+FD1-1;
        
     //NOTE #1: if(MOD==0)... else...下面属于else的处理

        for(int m=0; m<n-firstDig; m++){ //TODO bug here, MOD=0:n6,k112
            result+='0'+nums[m];
        }

        
        result+='0'+nums[realFirstDig];
        //cout<<result<<"x"<<endl;

        vector<int> newnums;
        for(int m=n-firstDig; m<n; m++){
            if(m!=realFirstDig)
            newnums.push_back(nums[m]);
        }
        
        result += helper(i-1, MOD, newnums);
        
        return result;
    }
    }
};
