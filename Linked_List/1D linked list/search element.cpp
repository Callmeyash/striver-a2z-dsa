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
    Node(int data1,Node* next1){
        next = next1;
        data = data1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

bool searchint(Node* head,int target){
    int count = 0;
    Node* temp = head;
    while(temp->next!= NULL){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    if(searchint(head,20)){
        cout<<"Found";
    }
    else{
        cout<<"NOT FOUND";
    }
    return 0;
}