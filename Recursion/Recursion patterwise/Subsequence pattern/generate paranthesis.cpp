#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Time: O(Cn × n) (where Cn is the nth Catalan number; each valid string has length 2n)
//Space: O(n) (recursion stack + current string)
void solve(int open,int close,int n,string s,vector<string>& ans){
    if(s.length()==2*n){
        ans.push_back(s);
        return;
    }
    if(open<n){
        solve(open+1,close,n,s+'(',ans);
    }
    if(close<open){
        solve(open,close+1,n,s+')',ans);
    }
}

int main(){
    int n = 3;
    vector<string> ans;
    solve(0,0,n,"",ans);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}