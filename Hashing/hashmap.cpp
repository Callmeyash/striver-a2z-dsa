#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    unordered_map<int,int> hash;
    for(int i=0;i<5;i++){
        hash[arr[i]]++;
    }
       int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
    return 0;
}