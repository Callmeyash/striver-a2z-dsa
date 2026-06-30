#include<iostream>
#include<vector>
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


void printList(Node* head) {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* vectorToDLL(vector<int>& arr){

    if(arr.empty())
        return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){

        Node* temp = new Node(arr[i], prev, NULL);

        prev->next = temp;

        prev = temp;
    }

    return head;
}
Node* reverse(Node* head){
    if(head==NULL || head->next== NULL){
        return head;
    }
    Node* curr = head;
    while(curr != nullptr){
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        head = curr;
        curr = temp;
    }
    return head;
}

Node* rotateright(Node* head,int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    int len = 1;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
        len++;
    }
    k = k%len;
    if(k==0)
        return head;

    tail->next = head;
    Node* newtail = head;
    for(int i =1;i<len-k;i++){
        newtail = newtail->next;
    }
    head = newtail->next;
    newtail->next = NULL;
    return head;
}

int main() {
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    Node* head = vectorToDLL(values);
    printList(head);
    Node* result = rotateright(head,3);
    printList(result);
    return 0;

    }