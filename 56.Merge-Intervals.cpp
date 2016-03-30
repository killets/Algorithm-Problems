//这题应该是直接参考的别人的算法，巧妙之处在于使用sort，自定义排序，来重整intervals
//重排后，大致有序，只需要判断是否重合并吸收更新

//3 improve by simplify comapre function: just return s.start< t.start
//2 try to fix runtime err: when input []
//1 basic method, O(SORT) O(nlogn)
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool customSort(Interval & s, Interval & t){
     return s.start < t.start;
    }
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), customSort);
        vector<Interval> res;
        int sz = intervals.size();
        if(sz<=1) {return intervals;}
        
        auto cur=intervals.begin();
        for(int i = 1; i<sz; i++){            
            if(intervals[i].start <= cur->end){
              if(intervals[i].end > cur->end){
               cur->end = intervals[i].end;
              }
            }
            else{
                res.push_back(*cur);
                cur =intervals.begin()+i;
            }
            
        }
        res.push_back(*cur);
        return res;
    }
};
