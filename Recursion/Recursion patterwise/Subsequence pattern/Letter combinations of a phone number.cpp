#include<iostream>
#include<vector>
using namespace std;

void func(int ind,string digits,string s,vector<string>&ans,vector<string>&combos){
    if(ind==digits.size()){
        ans.push_back(s);
        return;
    }
    int num = digits[ind]-'0';
    for(int i=0;i<combos[num].size();i++){
        func(ind+1,digits,s+combos[num][i],ans,combos);
    }
}

vector<string> LetterCombinations(string digits){
    if(digits.empty()) return {};
    vector<string> ans;
    vector<string> mp = {
                "", "", "abc", "def", "ghi",
                "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    string s="";
    func(0,digits,s,ans,mp);
    return ans;
}

int main(){
    string digits = "23";
    vector<string> ans = LetterCombinations(digits);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return
}