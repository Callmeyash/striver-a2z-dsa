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
//O(N),O(1)
bool cycledetection(Node* head){
    if(head==NULL || head->next == NULL ) return false;
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next == NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
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
    cout<<(cycledetection(head)?"YES CYCLE":"NO CYCLE");
}