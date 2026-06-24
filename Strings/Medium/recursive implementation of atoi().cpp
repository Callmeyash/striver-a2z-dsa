#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;   
//O(n),O(n)
long long solve(string &s,int i,long long num,int sign){
    if(i>=s.size() || !isdigit(s[i])){
        return sign*num;
    }
    num = num*10+(s[i]- '0');
    if (sign * num <= INT_MIN) return INT_MIN;
    if (sign * num >= INT_MAX) return INT_MAX;
    return solve(s,i+1,num,sign);
}

int myAtoi(string &s){
    int i = 0;
    int n = s.size();
    while(i<n && s[i]==' ') i++;
    int sign = 1;
    if(i<n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-') sign = -1;
        i++;
    }
    return (int)solve(s,i,0,sign);
}

int main(){
    string s = "-2147483649";
    cout<<myAtoi(s);
    return 0;
}
