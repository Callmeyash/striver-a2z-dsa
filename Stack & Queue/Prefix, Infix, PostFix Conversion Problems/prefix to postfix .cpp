#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    string prefixToPostfix(string s){
        stack<string> st;
        for(int i = s.size()-1;i>=0;i--){
            char ch = s[i];
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                string temp = first + second + ch;
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main() {
    Solution st;
    string prefix = "*-A/BC-/AKL";
    cout << "Postfix Expression: " << st.prefixToPostfix(prefix) << endl;
    return 0;
}