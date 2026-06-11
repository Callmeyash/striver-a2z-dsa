#include<iostream>
using namespace std;

/*bool checkprime(int n){
    int count=0;
    if(n<=1){
        return false;
    }
    for(int i=2;i<=n;i++){
        if(n%i==0){
            count++;
            if(count>1){
                return false;
            }
        }
    }
    return true;
}
*/
bool checkprime(int n){
    int count=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if (n / i != i) {
                count++;
            }
            if(count>2){
                return false;
            }   
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(checkprime(n)){
        cout<<"Prime Number";
    }
    else{
        cout<<"Not a Prime Number";
    }
}