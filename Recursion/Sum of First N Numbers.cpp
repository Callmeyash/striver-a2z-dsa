#include<iostream>
using namespace std;
/*int Sumoffirstnnumber(int n){
    return n*(n+1)/2;
    
}*/

int Sumoffirstnnumber(int n){
    if(n==1){
        return 1;
    }
    return n+Sumoffirstnnumber(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Sum of first "<<n<<" numbers is: "<<Sumoffirstnnumber(n)<<endl;
    return 0;
}
