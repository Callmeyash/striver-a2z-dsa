#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n),O(1)
int maximumnestingdepth(string s){
    int count = 0;
    int maxi = 0;
    for(char ch : s){
        if(ch=='('){
            count++;
            maxi = max(maxi,count);
        }
        else if(ch == ')'){
                count--;
            }
     }
     return maxi;
}

int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<maximumnestingdepth(s);
    return 0;
}