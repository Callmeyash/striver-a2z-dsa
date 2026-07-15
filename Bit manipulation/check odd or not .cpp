#include<iostream>
using namespace std;

bool checkodd(int n){
    return (n&1);
}

int main(){
    if(checkodd(10)){
        cout<<"ODD";
    }
    else{
        cout<<"EVEN";
    }
    return 0;
}

