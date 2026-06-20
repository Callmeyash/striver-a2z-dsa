#include<iostream>
using namespace std;
//Time Complexity: O(M), Space Complexity: O(1),
int nthroot(int n,int m){
    for(int i = 1;i<=m;i++){
        int power = pow(i,n);
        if(power==m){
            return i;
        }
        if(power>m){
            break;
        }
    }
    return -1;
}
//O(logm),O(1)
int nthrootb(int n,int m){
    int low = 1;
    int high = m;
    while(low<=high){
        long long mid = low + (high-low) /2;
        long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }
        if(ans==m) return mid;
        if(ans>m) high = mid-1;
        else low = mid+1;

    }
    return -1;
}

int main(){
    cout<<nthrootb(3,27);
    return 0;
}