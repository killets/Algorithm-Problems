 #include<iostream>
 using namespace std;
 
    bool isUgly(int num) {
        while(num%2==0) {
            num = num/2;
        }
        while(num%3==0) {
            num = num/3;
        }
        while(num%5==0) {
            num = num/5;
        }
        
        return (num==1);
    }

int main() {
    cout<<isUgly(14)<<endl;
}
