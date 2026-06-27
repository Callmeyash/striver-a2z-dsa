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
//O(n),O(n )
int helper(Node* node){
    if(node == NULL)
        return 1;
    int carry = helper(node->next);
    node->data += carry;
    if(node->data <10){
        return 0;
    }
    node->data = 0;
    return 1;
}

Node* addone(Node* head){
    int carry = helper(head);
    if(carry){
        Node* newhead = new Node(1);
        newhead->next = head;
        return newhead;
    }
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
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    
    Node* result = addone(head);
    printList(result);

    return 0;
}