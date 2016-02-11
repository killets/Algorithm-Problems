//别人算法妙在用getline来spilt字符串
//猜的考点是string和stack,果然对
// continue用得好
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> info;
        int n = path.length();
        n = path[n-1]=='/'? n-1: n;
        for(int i=0; i<n; i++){
            //if(path(i)=='/'){
                if(path[i]=='/') continue; // "/home//acb"
                string cur="";
                while(i<n && path[i]!='/'){
                    cur+=path[i];
                    i++;
                }
                //i--;
                if(cur=="."){}
                else if(cur==".."){
                    if(!info.empty())
                    info.pop();
                }else{
                    info.push(cur);
                }
            //}
        }
        
        if(info.empty()) return "/";
        string result="";
        while(!info.empty()){
            result = '/'+info.top()+result;
            info.pop();
        }
        return result;
    }
};
