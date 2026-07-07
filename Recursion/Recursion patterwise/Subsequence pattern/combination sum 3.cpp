#include<iostream>
#include<vector>
using namespace std;

void solve(int i,int tar,int n,vector<int>&ds,vector<vector<int>>&ans){
    if(tar==0 && n==0){
        ans.push_back(ds);
        return;
    }
    if(n<0 || tar<0) return;
    for(int j=i; j<=9;j++){
        ds.push_back(j);
        solve(j+1,tar-j,n-1,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k,int n){
    vector<vector<int>> ans;
    vector<int> ds;
    solve(1,n,k,ds,ans);
    return ans;
}

int main(){
    int k =3 ,n=9;
    vector<vector<int>> ans = combinationSum3(k,n);
    for(auto i :ans){
        for(auto j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}