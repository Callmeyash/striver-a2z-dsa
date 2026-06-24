#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;   
//O(n^2),O(1)
int expand(string &s,int left,int right){
    while(left>=0 && right <s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return right -left -1;
}

string longestpalindrome(string &s){
    int n = s.size();
    int start = 0;
    int maxLen = 1;
    for(int i =0;i<n;i++){
        int len1= expand(s,i,i);
        int len2= expand(s,i,i+1);
        int len = max(len1,len2);
        if(len>maxLen){
            maxLen = len;
            start = i - (len-1)/2;
        }
    }
    return s.substr(start,maxLen);
}

int main(){
    string s = "babad";
    cout<<longestpalindrome(s);
    return 0;
}