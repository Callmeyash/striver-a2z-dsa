#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Time: O(2ⁿ × n) (copying each subsequence into the answer can take up to n characters)
//Space: O(n) (recursion stack + current subsequence)
void solve(int i,string s,string curr,vector<string>&ans){
    if(i==s.length()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(s[i]);
    solve(i+1,s,curr,ans);
    curr.pop_back();
    solve(i+1,s,curr,ans);
}

vector<string> powerset(string s){
    vector<string> ans;
    solve(0,s,"",ans);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans = powerset(s);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}