#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(log(max(arr[]))*N),O(1)

int calculator(vector<int> &arr,int divisor){
    int n = arr.size();
    int sum  = 0;
    for(int i = 0;i<n;i++){
        sum += (arr[i]+divisor-1)/divisor;
    }
    return sum;
}

int smallestdivisorunderlimit(vector<int> &arr,int l){
    int low = 1;
    int high = *max_element(arr.begin(),arr.end());
    while(low<high){
        long long mid = low + (high -low) /2;
        int divisorsum = calculator(arr,mid);
        if(divisorsum<=l){
            high = mid;
        }
        else{
            low = mid +1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<smallestdivisorunderlimit(arr,8);
    return 0;
}