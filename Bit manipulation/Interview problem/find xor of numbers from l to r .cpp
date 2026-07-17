#include<iostream>
using namespace std;

int xorTillN(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;

    return 0;
}

int findXOR(int L,int R){
    return xorTillN(R)^xorTillN(L-1);
}

int main(){
    cout<<findXOR(3,5);
}