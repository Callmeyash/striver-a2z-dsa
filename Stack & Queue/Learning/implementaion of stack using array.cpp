#include<iostream>
#include<stack>
#include<vector>
#include<array>
using namespace std;

class ArrayStack{
private:
        int arr[1000];
        int top = -1;
    
public:
    ArrayStack(){
        top =-1;
    }

    void push(int x){
        if(top==999){
            return;
        }
        arr[++top] = x;
    }
    int pop(){
        if(top==-1){
            return -1;
        }
        return arr[top--];
    }
    int topp(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.topp() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }
}