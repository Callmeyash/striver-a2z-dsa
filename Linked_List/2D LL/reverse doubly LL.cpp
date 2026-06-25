#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std; 

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        next = next1;
        back = back1;
        data = data1;
    }
    Node(int data1){
        next = nullptr;
        back = nullptr;
        data = data1;
    }

};

Node* covertarr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print2dll(Node* head){
    while(head != nullptr){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head){
    if(head==NULL || head->next== NULL){
        return head;
    }
    Node* curr = head;
    while(curr != nullptr){
        Node* temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;
        head = curr;
        curr = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};

    // Convert array to DLL
    Node* head = covertarr2DLL(arr);

    // Reverse the DLL
    head = reverseDLL(head);

    // Print the reversed DLL
    print2dll(head);

    return 0;
}