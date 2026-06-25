#include<iostream>
using namespace std;
void printNameNTimes(string name, int n){
    if(n == 0){
        return ;
    }
    cout<<name<<endl;
    printNameNTimes(name,n-1);
}
int main(){
    string name;
    int n;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter the number of times to print the name: ";
    cin>>n;
    printNameNTimes(name,n);
    return 0;
}
