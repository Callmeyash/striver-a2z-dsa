#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;  

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
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"COUNT : "<< count;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    printList(head);
}