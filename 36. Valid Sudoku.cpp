//一开始着手做这个题还不太会，但是这个是easy题
//别人的算法是逐个读方格，如果不是空，则标记其所在的行，列和块中，那个数字已经被用了；
//这样如果已经被标记了，则说明前面已经出现了该数字，则非valid
//棋盘对应三个坐标记录文件

//2 1 is wrong since it wrongs the rule, we only need to check 9 9-grid areas
//1 use hash-multimap, 1: marked position (0,0)=0,(0,9)=9,(1,2)=11,.. 2:...
//   then check if same-key values breaks the rule.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
unordered_multimap<char,int> map;
int i=0;
for(auto & e: board)
for(auto & ee: e){
map.insert(make_pair(ee, i));
i++;
}
for(char x='1'; x<='9';x++){
    // Finds a range containing all elements whose key is k.
// pair<iterator, iterator> equal_range(const key_type& k)
auto its = map.equal_range(x);
for (auto it = its.first; it != its.second; ++it) {
   auto itnext = it;
   itnext++;
   for(;itnext!=its.second; ++itnext){
       int y1 = (it->second)/9;
       int x1 = it->second%9;
       int y2 = (itnext->second)/9;
       int x2 = itnext->second%9;
       //if(x1==x2||y1==y2||(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=9))
       //if(x1==x2||y1==y2||(abs(x1-x2)<=2&&abs(y1-y2)<=2))// wrong rule
       if(x1==x2||y1==y2||((x1/3==x2/3)&&(y1/3==y2/3)))
       return false;
   }
}


}
return true;
}
};
