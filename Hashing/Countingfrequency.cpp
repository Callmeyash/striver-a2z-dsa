#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int hash[100]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    return 0;

}
    */
class Solution {
public:
    int Freqency(int arr[],int n){
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){   
            hash[arr[i]]++;
        }
        for(auto it:hash){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}
};
int main(){
    Solution s;
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    s.Freqency( arr, n);
    return 0;
}
