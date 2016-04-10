//思路1： 两个都sort后比较是否相等， o(nlogn)
//2： sort一个后，另一个one pass将出现的字母在sort结果中标价，o(nlogn)
//3: hash一个后。另一个自己做减法，o(n)

class Solution {
private:
    enum{N=256};
public:
	bool isAnagram(string s, string t) {

		int a[N] = { 0 };
        int i;
        
        for(i=0;s[i]&&t[i];i++){
            a[s[i]]++;
            a[t[i]]--;
        }
        
        if(s[i]||t[i])
        return false;

		for (int k = 0; k < i; k++)
			if (a[s[k]])
				return false;
		return true;

	}
};
