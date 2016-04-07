//别人算法是利用两个custom的binary search分别找左右边界，很简洁
//我的算法比较笨拙，分情况然后解决

class Solution {
private:
int x = -1; // lower match, first currence
int y = -1; // higher match, last currence
bool xflag = false;
bool yflag = false;

public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int hi = nums.size()-1;
    	if(nums.empty() || target<nums[0] || target>nums[hi])
    		return  vector<int>{-1, -1};

    	Helper1(nums, target, 0, hi);

        return  vector<int> {x,y};
    }

    // not exist or only one match in last step of lo==hi, or matched in mid, then call helper2 and helper3
    void Helper1(vector<int>& nums, int target, int lo, int hi) {

    	while(1) {
      		if(lo>=hi ){
    			//cout<<"returned"<<endl;
    			if(nums[lo]==target)
    			x=y=lo;
    			break;
    		}
    		if(xflag==true&&yflag==true)
    			break;

    		int mid = lo + (hi-lo)/2;
    		if(nums[mid]<target)
    			lo = mid+1;
    		else if(nums[mid]>target)
    			hi = mid -1;
    		else {
    			x = y = mid;
    			if(nums[mid-1]!=target)
    				xflag = true;
    			if(nums[mid+1]!=target)
    				yflag = true;
    			if(nums[lo]==target) {
    				x = lo;
    				xflag = true;
    			}
    			if(nums[hi] ==target) {
    				y = hi;
    				yflag = true;
    			}

    			if(!xflag)
    				Helper2(nums, target, lo, mid-1);
    			if(!yflag)
    				Helper3(nums, target, mid+1, hi);
    		}

    	}
//    	cout<<"end"<<endl;
//    	cout<< x << " "<< xflag<<endl;
//    	cout<< y << " "<< yflag<<endl;

    }

    // helper2 find left-most target, first currence
    void Helper2(vector<int>& nums, int target, int lo, int hi) {
    	//cout<<"Helper2"<<endl;
    	while(1) {
    		if(lo>=hi || xflag)
    			break;
    		int mid = lo + (hi-lo)/2;
    		if(nums[mid]<target) {
    			lo = mid +1;
    		} else {
    			if(nums[mid-1]!=target) {
    				x = mid;
    				xflag = true;
    			} else {
    				hi = mid-1;
    			}
    		}

    	}

    	if(!xflag) {
    		x = lo;
    		xflag = true;
    	}
    }
    
    // helper3 find right-most target, last currence
    void Helper3(vector<int>& nums, int target, int lo, int hi) {
    	//cout<<"Helper3"<<endl;
    	while(1) {
    		if(lo>=hi || yflag)
    			break;
    		int mid = lo + (hi-lo)/2;
    		if(nums[mid]>target) {
    			hi = mid -1;
    		} else {
    			if(nums[mid+1]!=target) {
    				y = mid;
    				yflag = true;
    			} else {
    				lo = mid+1;
    			}
    		}

    	}

    	if(!yflag) {
    		y = lo;
    		yflag = true;}
    }

};
