#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(n log(sum(arr)))
int countPainter(vector<int>&arr,int limit){
    long long sum = 0;
    int painters  = 1;
    for(int board:arr){
        if(sum+board<=limit){
            sum += board;
        }
        else{
            painters++;
            sum = board;
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int>&arr,int k){
    long long low = *max_element(arr.begin(),arr.end());
    long long high = accumulate(arr.begin(),arr.end(),0LL);
    while(low<high){
        long long mid = low +(high-low) /2;
        int painter = countPainter(arr,mid);
        if(painter<=k){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {5, 5, 5, 5};
    cout<<findLargestMinDistance(arr,2);
    return 0;
}