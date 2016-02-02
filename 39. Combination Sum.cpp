// 这道题是以前扫过的，不会做，现在会了！

// 别人算法用的是backtracking, for(e:candidates){push，算combin，然后pop};
// 学到的东西是backtracking和recursive居然可以相通，解决同一个问题，结构还比较类似。
// -----------------------------------------------
// vesion 2.1: 更改vector的merge方法，回升到46%,看来还是简单的loop快，见Note#3
// vesion 2: 但是看起来速度下降了很多，由57%到20%
// use only single function, still in recursive way

class Solution {
public:
    // DELET HELPER, USE SINGLE FUNCTION
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        std::sort(candidates.begin(), candidates.end()); 
        //vector<int>::iterator it = candidates.begin();
        int n=candidates.size();
        for(int i=0; i<n; i++) {
            
             if(candidates[i]==target) {
                 vector<int> cur={candidates[i]}; //take out one element
                 result.push_back(cur);
                 //return result;
             } else if(candidates[i]<target){ 
                if (target-candidates[i] >= candidates[i]){//Note #1, speed up as above Note，never find a smaller number
                 vector<int>::iterator a = candidates.begin()+i; //checked element can't be used again, against duplicates
                 vector<int>::iterator b = candidates.end();
                 vector<int> newv(a,b);
                  //helper(newv, target-candidates[i],cur,result);   //Note #2, Important change
                 vector<vector<int>> sub = combinationSum(newv,target-candidates[i]);
                 if(!sub.empty()){ // if sub problem has solution
                     for(auto & e: sub){ // put "cur+sub" into result
                        /* 
                         vector<int> AB;
                         AB.reserve( cur.size() + e.size() ); // preallocate memory
                         AB.insert( AB.end(), cur.begin(), cur.end() );
                         AB.insert( AB.end(), e.begin(), e.end() ); */
                         
                         vector<int> AB(1+e.size()); //Note #3
                         AB[0]= candidates[i];
                         for(int i=0; i<e.size();i++)
                            AB[i+1]=e[i];
                            
                         result.push_back(AB);
                     }
                 }
                }
             }else
                break;
        }
        
        return result;
    }
};
// ------------------------------------------------------------------------------------------------
// 我的想法是递归，比如【2，3，6，7】找8，可以先拿出2，即变成【2，3，6，7】找6；
// 也可以是拿出3，再【2，3，6，7】找5；
// 为了保证不重复，要求先sort，然后不找比当前数小的数，即这个解应该是前面小数开头时已经找到了。
// 代码麻烦在不知道怎样把这些递归的结果拼在一起作为返回值，因此想到了hepler加入cur和result参数；
// helper中while各循环开始时的cur应该一样，所以后面再用到了tmp；
// helper和主函数结构想法都差不多，下一步想办法简化。

// Wrong Answer input:[8,7,4,3] find 11, cause is that I assume sorted increasly
// so first task is sorting them in non-descending order.

// basic idea is use recursive way to find a solution
// take out element one by one,as e, and find target-e in candidate set[Note A];
// then remove e from candidate set, take out second elment, do the same thing again;

// Note A: in this part, it's another similar recursive function
// different part is outter loop doesn't allow used candidate appear again, inner can,
// while both not allow find smaller number in next loop

// some elments can't used again is the key to prevent duplicates
class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int> cur, vector<vector<int>>& result){
            vector<int>::iterator it = candidates.begin();
            while(it!=candidates.end()&&*it<=target){
               
                if(*it==target){
                    cur.push_back(*it);
                    result.push_back(cur);
                    //set flag;
                    //return;
                 }else {  //Note, fixed [2,2,3],[2,3,2] problem
                if((target-*it)>=*it){
                    
                    //cur.push_back(*it); //Note!!! here is what I did wrongly. eg.[2,4,5]find10,result[2,2,2,2,4]
                    vector<int> tmp = cur;
                    tmp.push_back(*it);
                    vector<int> newv(it, candidates.end());
                    helper(newv, target-*it,tmp, result);
                } else{
                    //cur.pop_back(); //???
                }
                }
                
                it++;
            }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        std::sort(candidates.begin(), candidates.end()); 
        //vector<int>::iterator it = candidates.begin();
        int n=candidates.size();
        for(int i=0; i<n; i++) {
            vector<int> cur={candidates[i]}; //take out one element
             if(candidates[i]==target) {
                 result.push_back(cur);
                 //return result;
             } else if(candidates[i]<target){ 
                if (target-candidates[i] >= candidates[i]){//Note, speed up as above Note，never find a smaller number
                 vector<int>::iterator a = candidates.begin()+i; //checked element can't be used again, against duplicates
                 vector<int>::iterator b = candidates.end();
                 vector<int> newv(a,b);
                 helper(newv, target-candidates[i],cur,result);
                }
             }else
                break;
        }
        
        return result;
    }
};
//-----------------------------------------------------------------------------

int main() {
Solution slu;
vector<int>can{2,3,7};
vector<vector<int>> ans=slu.combinationSum(can, 7);
for(auto& e: ans){
for(auto ee: e)
cout<<ee<<" ";
cout<<endl;
}

/* Harder test
vector<int> can{1,2,3,4,5,6,7,8,9};
slu.combinationSum(can, 16);
*/
}
