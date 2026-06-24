#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;   
//O(n),O(1)
int romantonumeral(string s ){
    int res = 0;
    unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
    
    for(int i = 0;i<s.size();i++){
        if(i + 1 < s.size() && roman[s[i]]<roman[s[i+1]]) res -=roman[s[i]];
        else{
            res += roman[s[i]];
        }
    }
    return res;
}

int main(){
    string s = "LVIII";
    cout<<romantonumeral(s);
    return 0;
}