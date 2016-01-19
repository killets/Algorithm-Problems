 #include<iostream>
 #include<vector>
 
 using namespace std;
    
    int climbStairs(int n) {
        vector<int> a(n+1);
        a[0] = 1;
        a[1] = 1;
        for(int i=2; i<=n; i++) {
        a[i] = a[i-1]+a[i-2];
        }
        return a[n];      
    }

int main() {
    cout<<climbStairs(3)<<endl;
}
