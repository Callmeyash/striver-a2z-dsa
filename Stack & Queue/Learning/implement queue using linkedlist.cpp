#include<iostream>
#include<vector>
using namespace std;

class LInkedListQueue{
    class Node{
        public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
    };
    Node* front;
    Node* rear;
    public:
    LInkedListQueue(){
        front = nullptr;
        rear = nullptr;
    }
    void push(int x){
        Node * temp = new Node(x);
        if(front == nullptr){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    int pop(){
        if(front == nullptr){
            return -1;
        }
        Node* temp= front;
        int x = temp->data;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return x;
    }
    int peek(){
        if(front == nullptr){
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return front == nullptr;
    }
};

int main() {
    LInkedListQueue q;

    vector<string> commands = {"LinkedListQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};

    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListQueue") {
            cout << "null ";
        }
    }

    return 0;
}