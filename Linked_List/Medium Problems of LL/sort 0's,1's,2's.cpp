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

Node* sorting(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node dummy0(-1);
    Node dummy1(-1);
    Node dummy2(-1);
    Node* zeroes = &dummy0;
    Node* ones = &dummy1;
    Node* twos = &dummy2;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            zeroes->next = temp;
            zeroes = zeroes->next;
        }
        else if(temp->data == 1){
            ones->next = temp;
            ones = ones->next;
        }
        else{
            twos->next = temp;
            twos = twos->next;
        }
        temp = temp->next;
    }
    
    zeroes->next = (dummy1.next!=NULL)?dummy1.next:dummy2.next;
    if (dummy1.next) {
    ones->next = dummy2.next;
    }
    twos->next = NULL;
    return dummy0.next;
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
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head = sorting(head);
    return 0;
}