#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(√n)
int squareroot(int n ){
    int ans = 1;
    for(int i = 1;i<=n;i++){
        if(i*i<=n){
            ans = i;
        }
        else {
            break;
        }
    }
    return ans;
}
//O(logn),O(1)
int squareroot1(int n){
    if (n < 2) return n;
    int ans = 1;
    int low = 1;
    int high = n/2;
    
    while(low<=high){
        int mid = low + (high-low) /2;
        if(mid*mid <=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 25;
    cout<<squareroot1(n);
    return 0;
}
