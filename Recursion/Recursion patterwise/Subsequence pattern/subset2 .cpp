#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int ind,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        solve(i+1,arr,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> subset(vector<int>& arr){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    solve(0,arr,ds,ans);
    return ans;
}

int main(){
    vector<int> arr={1,2,2};
    vector<vector<int>> ans = subset(arr);
    for(auto i :ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}