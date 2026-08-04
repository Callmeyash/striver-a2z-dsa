#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    stack<int> st;
    for(int as : asteroids){
        bool destroyed = false;

        while(!st.empty() && st.top()>0 && as <0){
            if(abs(st.top())<abs(as)){
                st.pop();
            }
            else if(abs(st.top())== abs(as)){
                st.pop();
                destroyed = true;
                break;
            }
            else{
                destroyed = true;
                break;
            }
        }
        if(!destroyed){
            st.push(as);
        }
    }
    vector<int> ans(st.size());
    for(int i = st.size()-1;i>=0;i--){
        ans[i]= st.top();
        st.pop();
    }
    return ans;
}