#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(n log m)              
int lowerbound(vector<int>&arr){
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();
    while(low<=high){
        long long mid = low + (high-low) /2;
        if(arr[mid]==1){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return ans;
}

int max1s(vector<vector<int>>& arr){
    int n= arr.size();
    int m = arr[0].size();
    int maxones = 0;
    int ans = -1;
    for(int i =0;i<n;i++){
        int firstone = lowerbound(arr[i]);
        int ones = m-firstone;
        if(ones>maxones){
            maxones=ones;
            ans = i; 
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    cout << "The row with maximum no. of 1's is: " << max1s(matrix) << '\n';
}