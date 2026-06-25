#include<iostream>
using namespace std;
int waytoupstair(int n){
    if(n==0 || n==1){
        return 1;
    }
    return waytoupstair(n-1)+waytoupstair(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<waytoupstair(n);
    return 0;
}