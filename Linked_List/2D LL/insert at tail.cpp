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

Node* convertarr2dll(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],prev,nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* insertnodeattail(Node* head,int k){
    Node* newnode = new Node(k);
    if(head==nullptr){
        return newnode;
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newnode;
    newnode->prev = tail;
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

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertarr2dll(arr);
    printList(head);
    head = insertnodeattail(head,5);
    printList(head);
}