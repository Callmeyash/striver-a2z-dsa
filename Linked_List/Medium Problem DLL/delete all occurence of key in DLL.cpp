#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data1,Node* prev1,Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }
    Node(int data1){
        data = data1;
    }
};

Node* deletespecific(Node* head,int tar){
    Node* temp = head;
    while(temp){
        if(temp->data==tar){
            Node* back = temp->prev;
            Node* front = temp->next;
            if(back){
                back->next = front;
            }
            else{
                head = front;
            }
            if(front){
                front->prev = back;
            }
            delete temp;
            temp = front;
        }
        else{
            temp= temp->next;
        }
    }
    return head;
}
