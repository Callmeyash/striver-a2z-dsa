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
Node* cycledetection(Node* head){
    if(head==NULL || head->next == NULL ) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            fast = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
    
}

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Create nodes
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;
    Node* result = cycledetection(head);

    if (result != NULL)
        cout << "Cycle starts at node with value: " << result->data << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}