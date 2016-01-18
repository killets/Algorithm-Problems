 #include<string>
 #include<iostream>
 using namespace std;

int next(int n) {
    int sum = 0;
    while(n) {
    int tmp = n%10;
    n= n/10;
    sum += tmp* tmp;
    }
    return sum;    
}

bool ishappy(int n) {
    int fast=n,  slow =n;
    do {
        slow = next(slow);
        fast = next(fast);
        fast = next(fast);
        if(fast ==1) return true;
    } while(fast!=slow);
    
    return false;
}

int main() {
    cout<<ishappy(29)<<endl;
}
