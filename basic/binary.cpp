1 将数转换为二进制
#include<iostream>
 #include<vector>
 
using namespace std;
struct exp2{
int num;
int pos;
};

// find closet 2^pos number to input num
struct exp2 closet2n(int num) {
    int b = 1;
    int pos = 0;
    while(num/2) {
    b*=2;
    num/=2;
    pos++;
    }
    return {b,pos};
}

// translate number into binary format 
vector<bool> d2b(int num) { 
 struct exp2 b= closet2n(num);
 int k = b.pos+1;
 vector<bool> digits(k);     
 while(b.num !=1) {
    digits[k-b.pos-1] = true;
    num -= b.num;
    b= closet2n(num);   
}
digits[k-1] = num ==0 ? false : true;
return digits;
}

int main() {
   struct exp2 x = closet2n(3);
    cout<<x.num<<" "<<x.pos<<endl;
    
    vector<bool> ans = d2b(15);
    
    for(bool x : ans)
    cout<<x;
    
}

2 二进制转换为数
3 二进制运算
