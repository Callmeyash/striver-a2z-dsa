#include<iostream>
#include<string>
#include<vector>
using namespace std;
//O(N),O(N)
bool rotatestring(string str,string goal){
    if(str.size()!=goal.size()) return false;
    string s = str+str;
    return s.find(goal) != string::npos;
}

int main() {
    string s = "rotation";
    string goal = "tionrota";
    cout << (rotatestring(s, goal) ? "true" : "false") << endl;
    return 0;
}