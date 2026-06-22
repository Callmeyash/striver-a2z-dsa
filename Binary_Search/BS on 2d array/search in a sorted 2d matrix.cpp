#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool search(vector<vector<int>>& arr,int target){
    int n = arr.size();
    int m= arr[0].size();
    int low =0;
    int high = n*m-1;
    while(low<=high){
        long long mid = low +(high-low)/2;
        int row = mid/m;
        int col = mid%m;
        if(arr[row][col]==target){
            return true;
        }
        else if(target>arr[row][col]) low = mid+1;
        else high = mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    cout<<search(arr,78);
    return 0;
}