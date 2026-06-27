#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
//O(n),O(1)
Node* removenthfromend(Node* head, int n){
    Node* fast = head;
    Node* slow = head;

    for(int i =0;i<n;i++){
        fast = fast->next;
    }
    if(fast==NULL){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast= fast->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);

    return head;
}

Node* printlist(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return head;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(1);
    head->next->next = new Node(2);

    printlist(head);
    head = removenthfromend(head,2);
    printlist(head);
    return 0;
}