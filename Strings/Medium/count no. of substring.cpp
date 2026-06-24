#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n),O(1)
int atmostk(string s, int k){
    if(k<0) return 0;
    int left = 0;
    int count = 0;
    unordered_map<char,int> mp;
    for(int right = 0;right<s.size();right++){
        mp[s[right]]++;
        while(mp.size()>k){
            mp[s[left]]--;
            if(mp[s[left]]==0){
                mp.erase(s[left]);
            }
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}
int countSubstr(string s, int k) {
        return atmostk(s, k) - atmostk(s, k-1);
}

int main(){
    string s = "pqpqs";
    cout<<countSubstr(s,2);
    return 0;
}