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
Node* removemiddle(Node* head){
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete(slow);

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
    head = removemiddle(head);
    printlist(head);
    return 0;
}