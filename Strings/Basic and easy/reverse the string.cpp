#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reversestring(string s){
    vector<string> words;
    string word;
    for(char ch : s){
        if(ch!= ' '){
            word += ch;
        }
        else{
            words.push_back(word);
            word.clear();
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }
    string ans;
    for(int i =words.size()-1;i>=0;i--){
        ans += words[i];
         if(i!=0)
            ans += " ";
    }
    return ans;
}

int main() {
    string s = " amazing coding skills ";
    cout << reversestring(s) << endl;
    return 0;
}