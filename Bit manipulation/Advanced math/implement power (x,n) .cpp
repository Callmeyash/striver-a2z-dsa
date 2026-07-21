#include<iostream>
using namespace std;

double mypow(double x,int n){
    long long power = n;
    if(power < 0){
        x = 1/x;
        power = -power;
    }
    double ans = 1;
    while(power>0){
        if(power%2==1){
            ans *= x;
        }
        x *= x;
        power /=2;
    }
    return ans;
}

int main(){
    int x = 3;
    int n = 5;
    int res = mypow(x,n);
    cout<<res;
    return 0;
}