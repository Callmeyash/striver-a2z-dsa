#include<iostream>
#include<string>
#include<vector>
using namespace std;
//O(n*m),O(1)
string longestcommon(vector<string>& str){
    string ans;
    for(int i = 0;i<str[0].size();i++){
        char ch = str[0][i];
        for(int j =1;j<str.size();j++){
            if(i>= str[j].size() || str[j][i]!=ch){
                return ans;
            }
        }
        ans +=ch;
    }
    return ans;
}