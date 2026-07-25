#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;
    
    if(ch == '+' || ch == '-')
        return 1;

    return -1;
}

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    for(int i = 0;i<s.size();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
        stack<char> st;
        string ans = "";

        for(char ch : s){
            if(isalnum(ch)){
                ans += ch;
            }
            else if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && st.top() != '(' && (priority(st.top())>priority(ch) || (priority(st.top()) ==  priority(ch) && ch == '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    string s = "(p+q)*(c-d)"; 
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;  // Output the prefix expression
    return 0;
}