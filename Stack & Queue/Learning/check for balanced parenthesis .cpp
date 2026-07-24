#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    bool isValid(string s){
        stack<char> st;
        for(char ch :s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty())
                    return false;

                if(ch == ')' && st.top() != '(')
                    return false;

                if(ch == ']' && st.top() != '[')
                    return false;

                if(ch == '}' && st.top() != '{')
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}