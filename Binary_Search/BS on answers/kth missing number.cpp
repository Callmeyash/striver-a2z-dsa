#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// /Time	Space
//O(log n)	O(1)
int missing(vector<int>& arr,int k){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        long long mid = low + (high-low) /2;
        int missing = arr[mid] - (mid+1);
        if(missing<k){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return (low+k);
}

int main(){
    vector<int> arr = {2,3,4,7,11};
    cout<<missing(arr,5);
    return 0;
}