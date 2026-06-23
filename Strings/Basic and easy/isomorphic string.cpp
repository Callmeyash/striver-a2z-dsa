#include<iostream>
#include<string>
#include<vector>
using namespace std;
//O(n),O(1)
bool isomorphicstring(string s,string t){
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();
    for(int i =0;i<n;i++){
        if(m1[s[i]]!=m2[t[i]]){
            return false;
        }
        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
    }
    return true;
}

  int main() {
      string s = "paper";
      string t = "title";
      if (isomorphicstring(s, t)) {
          cout << "Strings are isomorphic." << endl;
      } else {
          cout << "Strings are not isomorphic." << endl;
      }
      
      return 0;
  }