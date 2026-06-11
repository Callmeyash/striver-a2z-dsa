#include<iostream>
#include<string>

using namespace std;
bool armstrong(int n){
    int k = to_string(n).length();
    int sum = 0;
    int temp =n;
    while(temp>0){
        int r = temp%10;
        sum += pow(r,k);
        temp /= 10;
    }
    return sum == n;
}
int main(){
    int n;
    cin>>n;
    if(armstrong(n)){
        cout<<"Armstrong Number";
    }
    else{
        cout<<"Not an Armstrong Number";
    }
}