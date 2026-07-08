#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string &s,int left,int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solve(int index,string &s,vector<string>&ds,vector<vector<string>>&ans){
    if(index==s.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            ds.push_back(s.substr(index,i-index+1));
            solve(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>>ans;
    vector<string>ds;
    solve(0,s,ds,ans);
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<vector<string>>ans = partition(s);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}