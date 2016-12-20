// 先是tle，现在尝试更改，看能不能ac
// backtracking, also can be regarded as recursive
class Solution {
public:
    bool isMatch(string& s, string& p, int ss=0, int pp=0) {
        if(p.empty()) return s.empty();
        if(s.empty() || ss==s.length()) return count(p.begin()+pp, p.end(), '*') == p.length() - pp; //""    "******" "ho" "ho**"

        if(pp==p.length()-1) {
            if(p[pp] =='*') return true;
            if(ss==s.length()-1  && (s[ss]==p[pp] || p[pp]=='?') ) return true;
            return false;
        }
        // [1]
        if(p[pp]!='*') {
            if(s[ss]==p[pp] || p[pp]=='?') {
                ss += 1;
                pp += 1;
                return isMatch(s, p, ss, pp);
            } else
                return false;
        }else{ //'*'
             /*
            while(pp<p.length()-1 && p[pp] =='*') // skip all internal ****, but not last one
                pp +=1;
               
            for(int i=ss; i<s.length(); i++){
                if(isMatch(s, p, i, pp))
                    return true;
            }
            if(s.empty() || ss==s.length()) return count(p.begin()+pp, p.end(), '*') == p.length() - pp; //""    "******" "ho" "ho**"
            return false; */
            while(pp+1<p.length() && p[pp+1] =='*') // skip all internal ****, but not last one
                pp +=1;
            return isMatch(s, p, ss+1, pp) || isMatch(s, p, ss, pp+1);
        }
    }
};


// dp, dp[i][j] string s[0]~s[i-1] matchs p[0]~p[i-1], 
// fix tle problem : when pat is a '*', we need not to write that inner loop to match more
// think that if i-1, than dp[i-1][j] must be true when dp[i][j] want to be true,
// recursively, we can get dp[i-2][j]... dp[i-3][j], dp[i-k][j] = true; this just means that '*'
// can match many characters, it's the same as the loop we want to do
class Solution_dp_ac {
public:
    bool isMatch(string s, string p){
        if(p.empty()) return s.empty();
        if(s.empty()) return count(p.begin(), p.end(), '*') == p.length();
        
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=0; i<m+1; i++)  // i=0 important
            for(int j=1; j<n+1; j++) {
                if(p[j-1]!='*') {
                    if(s[i-1]==p[j-1] || p[j-1]=='?' && i>0)
                        dp[i][j] = dp[i-1][j-1];
                    else  // != or i==0
                        dp[i][j] = false;
                        
                } else { // '*', match empty
                        dp[i][j] = dp[i][j-1];  // also set [0][j] first row
                        // if match signle or more, string cannot be empty
                        if(i>0)
                            dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    
                        // for(int ii=0; ii<i; ii++) {  
                        //     dp[i][j] = dp[i][j] || dp[ii][j-1];
                        //     if(dp[i][j]) break;
                        // }
                }
                
            }
            
        return dp[m][n];    
    }
};

// 有一个没写完的实现，是想按字符块匹配，加快速度



// dp, dp[i][j] string s[0]~s[i-1] matchs p[0]~p[i-1], tle
class Solution_dp_tle {
public:
    bool isMatch(string s, string p){
        if(p.empty()) return s.empty();
        if(s.empty()) return count(p.begin(), p.end(), '*') == p.length();
        
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=0; i<m+1; i++)
            for(int j=1; j<n+1; j++) {
                if(p[j-1]!='*') {
                    if(s[i-1]==p[j-1] || p[j-1]=='?' && i>0)
                        dp[i][j] = dp[i-1][j-1];
                    else  // != or i==0
                        dp[i][j] = false;
                        
                } else { // '*', match empty
                        dp[i][j] = dp[i][j-1];  // also set [0][j] first row
                        // match single or more
                        for(int ii=0; ii<i; ii++) {   //match[i][j]=match[i+1][j]||match[i][j+1];
                            dp[i][j] = dp[i][j] || dp[ii][j-1];
                            if(dp[i][j]) break;
                        }
                }
                
            }
            
        return dp[m][n];    
    }
};



// memorization, just add mem
// memory limit exceed, try to use two 2-d bool array insted one 2-d int array
// contine of above, but TLE this time, try to use char array instead?
class Solution_mem_tle {
private:
    vector<vector<bool>> mem;
    vector<vector<bool>> visited;
public:
    bool isMatch(string s, string p){
        mem = vector<vector<bool>> (s.length()+1, vector<bool>(p.length()+1, 0));
        visited = vector<vector<bool>> (s.length()+1, vector<bool>(p.length()+1, 0));
        return isMatch(s,p, 0, 0);
    }
    bool isMatch(string& s, string& p, int ss, int pp) {
        if(visited[ss][pp]) return mem[ss][pp];
        if(p.empty()) {mem[ss][pp] = s.empty();  visited[ss][pp] = true; return s.empty();}
        if(s.empty() || ss==s.length())  {mem[ss][pp] = count(p.begin()+pp, p.end(), '*') == p.length() - pp;  visited[ss][pp] = true; return mem[ss][pp];}//""    "******" "ho" "ho**"

        if(pp==p.length()-1) {
            if(p[pp] =='*') { mem[ss][pp] = true; visited[ss][pp] = true; return true;}
            if(ss==s.length()-1  && (s[ss]==p[pp] || p[pp]=='?') ) { mem[ss][pp] = true; visited[ss][pp] = true; return true;}
            mem[ss][pp] = false;
            visited[ss][pp] = true; 
            return false;
        }
        // [1]
        if(p[pp]!='*') {
            if(s[ss]==p[pp] || p[pp]=='?') {
                ss += 1;
                pp += 1;
                mem[ss-1][pp-1] = isMatch(s, p, ss, pp);
                visited[ss-1][pp-1] = true; 
                return mem[ss-1][pp-1];
            } else{
                mem[ss][pp]  = false;
                visited[ss][pp] = true; 
                return false;
            }
        }else{ //'*'
            int newpp = pp; // Note!!! otherwise, pp is changed
            while(newpp<p.length()-1 && p[newpp] =='*') // skip all internal ****, but not last one
                newpp +=1;
            for(int i=ss; i<s.length(); i++){
                if(isMatch(s, p, i, newpp)) {
                    mem[ss][pp] = true;
                    visited[ss][pp] = true; 
                    return true;
                }
            }
            if(s.empty() || ss==s.length()) {mem[ss][pp] = count(p.begin()+newpp, p.end(), '*') == p.length() - newpp; visited[ss][pp] = true;  return mem[ss][pp];}//""    "******" "ho" "ho**"
            
            mem[ss][pp] = false;
            visited[ss][pp] = true; 
            return false; 
        }
    }
};



  //[1] // s used up
        // if(ss==s.length()-1) {
        //     cout<<"TODO"<<endl;
        // }
