#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n+klogk),O(k)
string sortcharacter(string s){
    unordered_map<char,int> freq;
    for(char ch : s){
        freq[ch]++;
    }
    vector<pair<char,int>> arr(freq.begin(),freq.end());
    sort(arr.begin(),arr.end(),[](pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second) return a.first < b.first;
        return a.second > b.second;
    });
    string ans = "";
    for(auto &p : arr){
        ans += string(p.second,p.first);
    }
    return ans;
}

int main(){
    string s = "tree";
    cout<<sortcharacter(s);
    return 0;
}