#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};

Node* copyrandomlist(Node* head){
    if(head==NULL) return NULL;
    Node* temp = head;
    while(temp){
        Node *copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }
    temp = head;
    while(temp){
        if(temp->random)
            temp->next->random = temp->random->next;
        
        temp = temp->next->next;
    }
    Node dummy(-1);
    Node* copy = &dummy;
    temp= head;
    while(temp){
        copy->next = temp->next;
        temp->next = temp->next->next;
        copy = copy->next;
        if(copy->next){
            copy->next = copy->next->next;
        }
        temp = temp->next;
    }
    return dummy.next;
}

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

// Main function
int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = copyrandomlist(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
