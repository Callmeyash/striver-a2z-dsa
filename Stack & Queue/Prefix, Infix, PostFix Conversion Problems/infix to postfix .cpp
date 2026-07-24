#include<stack>
#include<iostream>
using namespace std;

class Solution{
    public:
    int priority(char ch){
        if(ch == '^'){
            return 3;
        }
        if(ch == '*' || ch == '/'){
            return 2;
        }
        if(ch == '+' || ch == '-'){
            return 1;
        }
        return -1;
    }
    string infixtopostfix(string s){
        stack<char> st;
        string ans = "";
        for(char ch : s){
            if(isalnum(ch)){
                ans +=ch;
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
                while(!st.empty()&& st.top()!='(' && (priority(st.top())>priority(ch) || (priority(st.top())== priority(ch) && ch != '^'))){
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
        return ans;
    }
};

int main() {
    Solution st;
    string exp = "(p+q)*(m-n)"; 
    cout << "Infix expression: " << exp << endl;
    string ans = st.infixtopostfix(exp);
    cout<<ans<<endl;  
    return 0;
}