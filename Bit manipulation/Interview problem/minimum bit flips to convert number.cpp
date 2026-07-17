#include<iostream>
using namespace std;

int minBitFlips(int start,int goal){
    int x = start ^ goal;
    int count = 0;
    while(x){
        x = x & (x-1);
        count++;
    }
    return count;
}

int main(){
    int s = 10;
    int g = 7;
    cout<<minBitFlips(s,g);
    return 0;
}