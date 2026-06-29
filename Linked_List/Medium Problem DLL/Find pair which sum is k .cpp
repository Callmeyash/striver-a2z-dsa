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

vector<pair<int,int>> findpair(Node* head,int k){
    vector<pair<int,int>> ans;
    if(head==NULL) return ans;
    Node* left = head;
    Node* right = head;
    while(right->next){
        right = right->next;
    }
    while(left!=right && left->prev!=right){
        int sum = left->data + right->data;
        if(sum==k) {
        ans.push_back({left->data,right->data});
        left = left->next;
        right = right->prev;
    }
    if(sum < k ){
        left = left->next;
    }
    else{
        right = right->prev;
    }
    return ans;
} 
}
