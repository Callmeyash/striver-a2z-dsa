#include<iostream>
using namespace std;

void swap(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int n = 7;
    int m = 6;
    swap(n,m);
    cout<<'N'<< n<<endl;
    cout<<'M'<< m;
    return 0;
}