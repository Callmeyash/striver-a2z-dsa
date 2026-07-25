#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
    string postfixToPrefix(string s){
        stack<string> st;
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string second = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                string temp = ch + first + second;
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main(){
    Solution st;
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << st.postfixToPrefix(postfix) << endl;
    return 0;
}