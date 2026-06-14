#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& arr,int s){
    int n = arr.size();
    for(int i =0;i<n;i++){
        if(arr[i]==s){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<search(arr,6);
    return 0;
}