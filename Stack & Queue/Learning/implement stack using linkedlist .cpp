#include<iostream>
#include<vector>
using namespace std;

class LinkedListStack{
    class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
    };
    Node* topNode;
    public:

    LinkedListStack(){
        topNode = nullptr;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = topNode;
        topNode = temp;
    }
    int pop(){
        if(topNode == nullptr){
            return -1;
        }
        Node* temp = topNode;
        int x= temp->data;
        topNode = topNode->next;
        delete temp;
        return x;
    }
    int top(){
        if(topNode == nullptr){
            return -1;
        }
        return topNode->data;
    }
    bool isEmpty(){
        return topNode == nullptr;
    }
};

int main(){
    LinkedListStack st;
    vector<string> op = {"LinkedListStack","push","push","pop","top","isEmpty"};
    vector<vector<int>> in = {{},{3},{7},{},{},{}};
    for(int i =0;i<op.size();i++){
        if(op[i]=="push"){
            st.push(in[i][0]);
            cout<<"null ";
        }
        else if(op[i]=="pop"){
            cout<<st.pop()<<" ";
        }
        else if (op[i] == "top") {
            cout << st.top() << " ";
        } else if (op[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (op[i] == "LinkedListStack") {
            cout << "null ";
        }
    }
}
