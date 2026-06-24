#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;   
//O(n),O(1)
string reverseword(string s){
    string result = "";
    int i = s.size()-1;

    while(i>=0){
        while(i>=0 && s[i]==' '){
            i--;
        }
        if(i<0) break;
        int end = i;
        while(i>=0 && s[i]!=' '){
            i--;
        }
        string word = s.substr(i+1,end-i);
        if(!result.empty()){
            result +=" ";
        }
        result += word;

    }
    return result;
}

int main(){
    string s = "my name is yash";
    cout<<reverseword(s);
    return 0;
}