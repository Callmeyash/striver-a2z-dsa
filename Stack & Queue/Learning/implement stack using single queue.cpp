#include<iostream>
#include<queue>
using namespace std;

class QueueStack{
    queue<int> q;
public:
    void push(int x){
        q.push(x);
        int sz = q.size();
        for(int i =0;i<sz-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        if(q.empty()){
            return -1;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    int top(){
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
};

int main() {
    QueueStack st;
    vector<string> commands = {"QueueStack", "push", "push", 
                               "pop", "top", "isEmpty"};
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "QueueStack") {
            cout << "null ";
        }
    }

    return 0;
}