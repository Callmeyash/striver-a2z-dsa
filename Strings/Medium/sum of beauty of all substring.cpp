#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;   
//O(n^2),O(1)
int beautysum(string s){
    int n = s.size();
    int sum = 0;
    for(int i = 0;i<n;i++){
        unordered_map<char,int> mp;
        for(int j =i;j<n;j++){
            mp[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto &p : mp){
                maxi = max(maxi,p.second);
                mini = min(mini,p.second);
            }
            sum+= (maxi-mini);
        }
    }
    return sum;
}

int main() {
    string s = "xyx";
    cout << "Beauty Sum: " << beautysum(s) << endl;
    return 0;
}