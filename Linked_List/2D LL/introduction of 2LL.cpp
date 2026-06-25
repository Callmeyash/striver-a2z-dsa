#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;  

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
    Node* second = new Node(3);
    Node* third = new Node(4);
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = NULL;
    return 0;
}