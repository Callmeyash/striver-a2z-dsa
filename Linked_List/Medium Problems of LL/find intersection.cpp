#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
//O(n+m),O(n)
Node* intersection(Node* head1,Node* head2){
    unordered_set<Node*> st;
    while(head1!=NULL){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2)!=st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}
//O(n+m),O(1)
Node* getintersection(Node* h1,Node* h2){
    Node* la = h1;
    Node* lb = h2;
    while(la!=lb){
        la = (la==NULL)?h2:la->next;
        lb = (lb==NULL)?h1:lb->next;
    }
    return la;
}

Node* printlist(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    Node* head2 = new Node(9);
    head2->next = new Node(5);
    head2->next->next = new Node(4);
    head2->next->next->next = head->next->next->next;
    head2->next->next->next->next = new Node(0);
    Node* answerNode = getintersection(head, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->data << endl;
    
    return 0;
}