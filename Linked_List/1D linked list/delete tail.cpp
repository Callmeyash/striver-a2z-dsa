#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;  
//O(n),O(1)
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

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deletetail(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL) {delete head; return NULL;}
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    cout<<"Original"<<endl;
    printList(head);
    head = deletetail(head);
    cout<<"Now"<<endl;
    printList(head);
}