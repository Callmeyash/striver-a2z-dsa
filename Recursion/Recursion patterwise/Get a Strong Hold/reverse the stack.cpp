#include<iostream>
#include<stack>
using namespace std;
//O(n^2),O(n)
void insertatbottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int top = s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(top);
}
void reverse(stack<int> &s){

    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,top);
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    reverse(s);
    for(int i =0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}