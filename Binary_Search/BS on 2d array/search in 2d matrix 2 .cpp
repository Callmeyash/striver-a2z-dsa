#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(n+m),O(1)
bool find(vector<vector<int>> &arr,int target){
    int n = arr.size();
    int m = arr[0].size();
    int row = 0;
    int col = m-1;
    while(row<n && col>=0){
        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]>target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1,4,7,11}, {2,5,8,12}, {10,13,14,17} };
    cout<<find(arr,7);
    return 0;
}