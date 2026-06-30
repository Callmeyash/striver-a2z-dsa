#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode* child;
    ListNode(){
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int val1){
        val = val1;
        next = NULL;
        child = NULL;
    }
    ListNode(int val1,ListNode* next1,ListNode* next2){
        val = val1;
        next = next1;
        child = next2;
    }
};

ListNode* merge(ListNode* a,ListNode* b){
    ListNode dummy(-1);
    ListNode* temp = &dummy;

    while(a && b){

        if(a->val < b->val){
            temp->child = a;
            a = a->child;
        }
        else{
            temp->child = b;
            b = b->child;
        }

        temp = temp->child;
        temp->next = NULL;
    }

    if(a)
        temp->child = a;
    else
        temp->child = b;

    return dummy.child;

}

ListNode* flatten(ListNode* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    head->next = flatten(head->next);
    head = merge(head,head->next);
    return head;
}

void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}


int main() {
    // Create a linked list with child pointers
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);
    
    // Function call to flatten the linked list
    ListNode* flattened = flatten(head);
    
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}