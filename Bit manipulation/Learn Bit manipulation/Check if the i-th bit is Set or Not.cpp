#include<iostream>
using namespace std;

bool checkithbit(int n,int i){
    return (n & (1<<i));
}

int main(){
    cout<<checkithbit(13,3)?"SET":"NOT SET";
    return 0;
}

