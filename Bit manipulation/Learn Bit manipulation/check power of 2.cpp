#include<iostream>
using namespace std;

bool checkpower(int n){
    return n>0 && (n&(n-1))==0;
}

int main(){
    if(checkpower(10)){
        cout<<"YES";
    }
    else{
        cout<<"NOT";
    }
    return 0;
}

