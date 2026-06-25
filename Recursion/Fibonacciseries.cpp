#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    if(n==0){
        cout <<0;
    }
    else if(n==1){
        cout <<0 << " "<<1;
    }
    else {
        int secondLast = 0; 
        int last = 1;     

        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << secondLast << " " << last << " ";

        int cur=0;
        for (int i = 2; i <=n; i++) {
            cur = last + secondLast;   
            secondLast = last;       
            last = cur;
            cout << cur << " ";
        }
    }

    return 0;
}
