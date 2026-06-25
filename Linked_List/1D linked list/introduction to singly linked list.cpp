#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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

int main(){
    vector<int> s = {2,5,8,7};
    Node* y = new Node(s[0]);
    // Print memory location of node
    cout << y << '\n';
    // Print data stored in node
    cout << y->data << '\n';

    return 0;
}
