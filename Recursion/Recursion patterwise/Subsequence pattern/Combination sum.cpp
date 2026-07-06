#include<iostream>
#include<vector>
using namespace std;

//Time Complexity: O(2t * k) due to exploring all combinations up to the target with copying each valid combination of average length k.

//Space Complexity: O(k * x) to store all valid combinations, where x is the number of combinations and k is their average length.

void solve(int index,vector<int> &arr,int target,vector<int> &ds,vector<vector<int>> &ans){
    if(index==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[index]<=target){
        ds.push_back(arr[index]);
        solve(index,arr,target-arr[index],ds,ans);
        ds.pop_back();
    }
    solve(index+1,arr,target,ds,ans);
}

vector<vector<int>> combinationsum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, candidates,target,ds,ans);
    return ans;
}

int main(){
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationsum(arr,target);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}