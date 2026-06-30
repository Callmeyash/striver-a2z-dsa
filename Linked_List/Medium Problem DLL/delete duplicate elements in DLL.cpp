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

Node* removeduplicate(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    while(temp && temp->next){
        if(temp->data == temp->next->data){
            Node* duplicate = temp->next;
            Node* front = duplicate->next;
            temp->next = front;
            if(front){
                front->prev = temp;
            }
            delete(duplicate);
        }
        else temp = temp->next;
    }
    return head;
}

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

int main() {
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    Node* head = vectorToDLL(values);
    printList(head);
    
    Node* result = removeduplicate(head);
    printList(result);
    return 0;

    }