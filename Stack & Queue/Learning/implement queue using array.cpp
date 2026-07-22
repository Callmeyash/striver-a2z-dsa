#include<iostream>
#include<array>
#include<vector>
using namespace std;

class ArrayQueue{
private:
    int arr[1000];
    int front;
    int rear;
public:
    ArrayQueue(){
        front = 0;
        rear = -1;
    }
    void push(int x){
        if(rear == 999){
            return;
        }
        arr[++rear] = x;
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }
        return arr[front++];
    }
    int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        return front>rear;
    }
};

int main(){
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }
    return 0;
}