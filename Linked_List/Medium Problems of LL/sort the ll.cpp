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

//O(nlogn),O(1)
Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* l1,Node* l2){
    Node dummy(-1);
    Node* temp = &dummy;
    while(l1 && l2){
        if(l1->data <= l2->data){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1) temp->next = l1;
    else temp->next = l2;

    return dummy.next;
}

Node* sortnode(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* mid = middle(head);
    Node* right = mid->next;
    mid->next = NULL;
    Node* left = sortnode(head);
    right = sortnode(right);

    return merge(left,right);
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
    head = sortnode(head);
    printlist(head);
    return 0;
}