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

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* addnumber(Node* l1,Node* l2){
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node dummy(-1);
    Node* tail = &dummy;
    int carry =0;
    while(l1 || l2 || carry){
        int sum = carry;
        if(l1){
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum/10;
        tail->next = new Node(sum%10);
        tail = tail->next;
    }
    return reverse(dummy.next);
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

    Node* head1 = new Node(1);
    head1->next = new Node(0);
    head1->next->next = new Node(0);
    
    Node* result = addnumber(head,head1);
    printList(result);

    return 0;
}