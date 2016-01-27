// 和别人算法最大区别在于，别人直接使用现成的stack来实现新的MinStack；而我是从头实现；
// 另外别人的算法，有的是维护最小值所在的位置，而不是最小值。这样也值得学习。

// WRONG ANSWER 继续，凡是pop之后都要更新cur_min
// WRONG ANSWER 原因是pop完之后，cur_min 没有复位
/*
Input:
push(2147483646),push(2147483646),push(2147483647),top,pop,getMin,pop,getMin,pop,push(2147483647),top,getMin,push(-2147483648),top,getMin,pop,getMin
Output:
[2147483647,2147483646,2147483646,2147483647,2147483646,-2147483648,-2147483648,2147483646]
Expected:
[2147483647,2147483646,2147483646,2147483647,2147483647,-2147483648,-2147483648,2147483647]
*/


// push时更新最小值简单，但pop之后，最小值得遍历才知道；
// 所以干脆每次push时都push进输入的数和当前的最小值；但pop之后，cnt--即可
// 即每一层都维护一个当前最小值

class MinStack {
private:
    int* nums;
    int* min;
    int capacity;
    int cnt;
    int cur_min;
public:
    MinStack() {
    capacity = 20;
    cnt= 0;
    cur_min = INT_MAX;
    nums = new int [capacity];
    min= new int [capacity];
    }
    
    void push(int x) {
        if(cnt>=capacity)
        {
            int * p_top=new int[capacity*2];
            int * p_min=new int[capacity*2];
            for(int i=0; i<capacity; i++){
                p_top[i]=nums[i];
                p_min[i]=min[i];
            }
             delete[] nums;
             delete[] min;
             capacity*=2;
             nums = p_top;
             min = p_min;
        }
        nums[cnt]=x;
        cur_min = x < cur_min ? x:cur_min;
        min[cnt] = cur_min;
        cnt++;
    }

    void pop() {
        if(cnt<=0)
          throw string("Stack is empty");
        cnt--;
        if(cnt==0) cur_min = INT_MAX;     //Note!
        else cur_min = min[cnt-1];       // Note!!!!! WRONG ANSWER
    }

    int top() {
        if(cnt<1)  throw string("Stack is empty");
     return nums[cnt-1];   
    }

    int getMin() {
        if(cnt<1)  throw string("Stack is empty");
        return min[cnt-1];
    }
};

int main() {
MinStack slu;
slu.push(2);
slu.push(1);
slu.push(3);
cout<<slu.getMin()<<endl;
slu.push(0);
cout<<slu.getMin()<<endl;
cout<<slu.top()<<endl; //0
slu.pop();
cout<<slu.getMin()<<endl;
cout<<slu.top()<<endl; //3
slu.pop();
slu.pop();
cout<<slu.getMin()<<endl;
cout<<slu.top()<<endl; //2
slu.pop();

slu.push(5);
cout<<slu.getMin()<<endl; // should not be 0
cout<<slu.top()<<endl; //2
}
