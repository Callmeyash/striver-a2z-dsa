//O(min(na,nb))) time complexity
#include<iostream>
using namespace std;
int gcd(int a, int b){
    int ans = 1;
    for(int i=int(min(a,b));i>=1;i--){
        if(a%i==0 && b%i==0){
            ans = i;
            break;
        }
    }
    return ans;
}
int main(){
    int a = 9, b = 125;
    cout<<gcd(a,b);
    return 0;
}

//Euclid's algorithm
int gcd(int a,int b){
    while(a!=0 && b!=0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a==0){
        return b;
    }
    else{
        return a;
    }

}
int main(){
    int a = 9, b = 120;
    cout<<gcd(a,b);
    return 0;
}