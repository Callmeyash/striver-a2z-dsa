#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int index,vector<int> &arr,int tar,vector<int> &ds,vector<vector<int>> &ans){
    if(tar==0){
        ans.push_back(ds);
        return;
    }
    for(int i = index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>tar) break;
        ds.push_back(arr[i]);
        solve(i+1,arr,tar-arr[i],ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationsum2(vector<int> &candidates, int target){
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, candidates,target,ds,ans);
    return ans;
}

int main(){

    vector<int> arr = {10,1,2,7,6,1,5};

    int target = 8;

    vector<vector<int>> ans = combinationsum2(arr, target);

    for(auto v : ans){
        for(int x : v)
            cout << x << " ";
        cout << endl;
    }
}