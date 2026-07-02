#include<iostream>
#include<stack>
using namespace std;
//O(n^2),O(n)
void insert(stack<int> &s,int temp){
    if(s.empty() || s.top()<=temp){
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s,temp);
    s.push(top);
}

void sortstack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sortstack(s);
    insert(s,temp);
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
    sortstack(s);
    for(int i =0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}