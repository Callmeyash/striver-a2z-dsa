#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack{
    public:
    stack<pair<int,int>> st;
    MinStack(){
    }
    void push(int x){
        if(st.empty()){
            st.push({x,x});
        }
        else{
            int mini = min(x,st.top().second);
            st.push({x,mini});
        }
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
};

int main(){
    MinStack st;
    st.push(4);
    st.push(5);
    st.push(8);
    st.push(9);
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.getMin()<<endl;
}