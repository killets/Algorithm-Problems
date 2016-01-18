 // digital root: https://en.wikipedia.org/wiki/Digital_root
 #include<iostream>
 using namespace std;

int ishappy(int n) {
int a = (n-1)/9;
cout<<a<<endl;
return n- 9*a;
}

int main() {
    cout<<ishappy(19)<<endl;
}
