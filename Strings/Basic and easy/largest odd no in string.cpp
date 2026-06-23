#include<iostream>
#include<string>
#include<vector>
using namespace std;
//O(n),O(1)
string largestoddnumber(string s){
    for(int i= s.size()-1;i>=0;i--){
        int digit = s[i]-'0';
        if(digit%2==1){
            if(s[0]=='0')
            return s.substr(1,i+1);
            else return s.substr(0,i+1);
        }
    }
    return "";
}

int main(){
    string  s = "0214638";
    cout<<largestoddnumber(s);
    return 0;
}