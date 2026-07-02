#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Time O(2ⁿ),Space O(n)
void solve(int n,string s,vector<string> &ans){
    if(s.length()==n){
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    solve(n,s,ans);
    s.pop_back();
    if(s.length()==0 || s.back()=='0'){
        s.push_back('1');
        solve(n,s,ans);
        s.pop_back();
    }
}

vector<string> generateBinaryStrings(int n){
    vector<string> ans;
    string s = "";
    solve(n,s,ans);
    return ans;
}

void generate(int n,string s,vector<string> &ans){
    if(s.length()==n){
        ans.push_back(s);
        return;
    }
    generate(n,s+'0',ans);
    if(s.length()==0 || s.back()!= '1'){
        generate(n,s+'1',ans);
    }
}

int main(){
    int n ;
    cin>>n;
    vector<string> ans;
    string s  = "";
    generate(n,s,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}