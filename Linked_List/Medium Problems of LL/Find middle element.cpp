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
//O(n+n/2),O(1)
Node* findmidelement(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    int mid = count/2 +1;
    temp = head;
    while(temp!=NULL){
        mid = mid-1;
        if(mid==0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}
//Tortoise and Hore algo O(N),O(1)
Node* findmidelement1(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertarr2dll(arr);
    Node* middlenode = findmidelement1(head);
    cout<<middlenode->data;
    return 0;
}