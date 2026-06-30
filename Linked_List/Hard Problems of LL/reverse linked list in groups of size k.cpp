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

Node* getkthNode(Node* temp,int k){
    k--;
    while(temp && k){
        temp = temp->next;
        k--;
    }
    return temp;
}

Node* reversekthgroup(Node* head,int k){
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp){
        Node* kthnode = getkthNode(temp,k);
        if(kthnode==NULL){
            if(prevLast)
                prevLast->next = temp;

            break;
        }
        Node* nextnode = kthnode->next;
        kthnode->next  = NULL;
        Node* newHead = reverse(temp);
        if(temp==head){
            head= newHead;
        }
        else{
            prevLast->next = newHead;
        }
        prevLast = temp;
        temp = nextnode;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    Node* head = vectorToDLL(values);
    printList(head);
    Node* result = reversekthgroup(head,3);
    printList(result);
    return 0;

    }