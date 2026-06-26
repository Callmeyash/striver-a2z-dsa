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
bool ispalindrome(Node* head){
    if(head== NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    Node* first = head;
    Node* second = slow->next;
    while(second!=NULL){
        if(first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    return true;
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
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    cout<<(ispalindrome(head)?"YES":"NO");
    return 0;
}