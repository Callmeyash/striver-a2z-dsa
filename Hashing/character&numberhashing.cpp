#include<iostream>
#include<vector>
using namespace std;

/*int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[100]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
       int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}
*/
int main(){
    string s;
    cin>>s;

    int hash[26]={0};
    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']++;
    }
       int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetching:
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}