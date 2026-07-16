#include<iostream>
using namespace std;

int setrightmostbit(int n){
    if((n & (n+1))==0){
        return n;
    }
    return n | (n+1);
}

int main(){
    int n = 7;
    cout<<setrightmostbit(n);
    return 0;
}