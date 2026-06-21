#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(n log(sum(arr)))
int countsum(vector<int>&arr,int limit){
    long long sum = 0;
    int count  = 1;
    for(int num:arr){
        if(sum+num<=limit){
            sum += num;
        }
        else{
            count++;
            sum = num;
        }
    }
    return count;
}

int splitarray(vector<int>&arr,int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<high){
        long long mid = low +(high-low) /2;
        int cnt = countsum(arr,mid);
        if(cnt<=k){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<splitarray(arr,3);
    return 0;
}