我以为是要用new，这样要定义成指针；
实际上不用new

```
//所有新数先放maxH里，然后放进来一个就拿出去一个，拿出去的是maxH的最大值，top，
//放入minH中，minH如果这时平衡了就不动，如果size比maxH多，就拿出最小的放回maxH
// maxH中存小数，minH中存大数，且无交集； 如果为奇数，maxH多1； 为偶数，相等
class MedianFinder {
public:
     // Adds a number into the data structure.
    void addNum(int num) {
       maxH.push(num);
       int t = maxH.top();
       maxH.pop();
       minH.push(t);
       if(minH.size()>maxH.size()){
           maxH.push(minH.top());
           minH.pop();
       }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(maxH.empty()) return 0.0;
        return maxH.size()>minH.size()? maxH.top(): (maxH.top()+minH.top())/2.0;
    }
    
private:
 priority_queue<int, vector<int>, less<int>> maxH;
 priority_queue<int, vector<int>, greater<int>> minH;
    
};



// Multisets are typically implemented as binary search trees.
// add o(logn) findmedian o(n)
class MedianFinder_TLE {
public:
    MedianFinder_TLE() {
    mset = new multiset<int>();
    }
    
     // Adds a number into the data structure.
    void addNum(int num) {
       mset->insert(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        if(mset->empty()) return INT_MIN;
        int n=mset->size();
        auto it = mset->begin();
        
        for(int k=0; k< (n-1)/2; k++)
        ++it;
        
        if(n&0x01) return *it;
        else {
            double tmp = *it;
            it++;
            return (tmp+ *it)/2.0;
        }
    }
    
private:
 multiset<int> *mset;
    
};
```
