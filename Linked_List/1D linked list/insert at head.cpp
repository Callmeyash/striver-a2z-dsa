#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;  
//O(1),O(1)
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        next = next1;
        data = data1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* inserthead(Node* head,int val){
    Node* newnode = new Node(val,head);
    return newnode;
}
void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(3);
    cout<<"Original"<<endl;
    printList(head);
    head = inserthead(head,1);
    cout<<"Now"<<endl;
    printList(head);
}