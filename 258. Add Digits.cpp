 #include<string>
 #include<iostream>
 using namespace std;

int next(int n) {
    int sum = 0;
    while(n) {
    int tmp = n%10;
    n= n/10;
    sum += tmp;
    }
    return sum;    
}

int ishappy(int n) {
    int slow =n;
    do {
        slow = next(slow);       
    } while(slow>=10);
    
    return slow;
}

int main() {
    cout<<ishappy(29)<<endl;
}
