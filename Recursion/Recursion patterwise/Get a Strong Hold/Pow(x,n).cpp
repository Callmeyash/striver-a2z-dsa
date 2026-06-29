#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n==0){
        return 1;
    }
    double half = pow(x,n/2);
    if(n%2==0){
        return half*half;
    }
    else{
        return half*half*x;
    }
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<pow(x,n);
    return 0;
}