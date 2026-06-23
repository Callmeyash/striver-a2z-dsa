#include<iostream>
#include<string>
#include<vector>
using namespace std;
//O(n),O(1)
bool checkanagrams(string s,string t){
    int f[26] = {0};
    for(char ch : s){
        f[ch-'A']++;
    }
    for(char ch : t){
        f[ch-'A']--;
    }
    for(int i =0;i<26;i++){
        if(f[i]!=0) return false;
    }
    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if (checkanagrams(Str1, Str2))
        cout << "True" << endl;  // Output "True" if they are anagrams
    else
        cout << "False" << endl;  // Output "False" if they aren't anagrams

    return 0;
}