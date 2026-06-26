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
    Node* prev;
    Node(int data1,Node* prev1,Node* next1){
        prev = prev1;
        data = data1;
        next = next1;
    }
    Node(int data1){
        prev = nullptr;
        data = data1;
        next = nullptr;
    }
};

Node* oddevenlist(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = even;
    while(even!=NULL && even->next !=NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Create nodes
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);
    head = oddevenlist(head);
    printList(head);
    return 0;
}