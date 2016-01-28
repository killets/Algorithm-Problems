// 好题！
// 别人的算法复杂度为O(n),用到双指针；双指针的移动是基于两点观察，
// 双指针首先指向首尾，第一，如果左线矮，那么此时已经是左线最大的面积了，
// |____________
// 因为左线固定是短板，右线已经是最远的了，向左移动右线，只会使底边变短，即使新的右线高，也受
// 左线限制，所以没必要考虑移动右线了；于是，考虑下一个左线的位置；
// 第二，如果右线矮，一样的道理，对称的，我们只能再移动右线了，底边变短，但寻找高一点的右线，看有没
// 更大的面积；每次的面积都和max值比较以更新。

// 其实，我观察到了其中的一点点，即不用看比左线低的了；另外，我意识中也有双指针，因为一开始肯定是框两边
// 比较大，但没有想到双指针怎么移动，尤其是中间有两条高线时怎么解释。 现在可以解释了：假设左线或右线有一根
// 线移动到了中间高位置，那么另一个线低，于是向中间移动，移动到中间另一高位置。这种情况也能解决。

// Time Limit Exceeded 

// my idea is search every combination of two out of n points to calculate
// maximum (j-i)*min(ai,aj); O(n^2)
// observation#1, if when outter loop is i, we get a max no mater what j is,
// then in all next loop ,if k>i, but heigh[k] <height[i], 
// then we are sure that k-th point can't be the choice

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max =0;
        int left=0;
        for(int i=0; i<height.size();i++) {
            if(height[i]<left) continue; //observation #1
            for(int j=i+1; j<height.size();j++){
                int tmp = (j-i)*min(height[i],height[j]);
                if(tmp>max){
                    max = tmp;
                    left = height[i];
                }
            }
        }
        return max;
    }
};
