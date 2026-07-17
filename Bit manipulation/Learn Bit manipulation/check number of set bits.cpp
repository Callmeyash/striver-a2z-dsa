#include<iostream>
using namespace std;

int countsetbits(int n){
    int cnt = 0;
    while(n){
        n = n& (n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    cout<<countsetbits(13);
}