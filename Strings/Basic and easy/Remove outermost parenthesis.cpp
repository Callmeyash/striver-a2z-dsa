#include<iostream>
#include<string>
using namespace std;
//O(n),O(n)
string removeparenthesis(string s){
    string ans;
    int count = 0;
    for(char ch :s){
        if(ch=='('){
            if(count>0){
                 ans +=ch;
                }
            count ++;
        }
        else{
            count--;
            if(count>0) ans +=ch; 
        }
    }
    return ans;
}

int main() {
    string s = "(()())(())";  
    string ans = removeparenthesis(s);
    cout << "The result is: " << ans << endl;

    return 0;
}