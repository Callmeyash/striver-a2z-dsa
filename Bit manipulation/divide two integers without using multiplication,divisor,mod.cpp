#include<iostream>
using namespace std;

int divide(int dividend,int divisor){
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    bool isPositive = ((dividend>=0)==(divisor>=0));
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long ans = 0;

    while(n>=d){
        int cnt = 0;
        while(n>=(d<<(cnt+1))){
            cnt++;
        }
        ans+=(1LL<<cnt);
        n -= (d<<cnt);
    }
    if(!isPositive)
        ans = -ans;

    return (int)ans;
    
}


int main() {

    int dividend, divisor;

    cin >> dividend >> divisor;

    cout << divide(dividend, divisor);

    return 0;
}