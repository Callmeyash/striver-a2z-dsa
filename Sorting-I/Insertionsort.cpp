#include<iostream>
using namespace std;
#include<vector>

void insertionsort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    vector<int> arr = {5,3,2,4,1,6};
    insertionsort(arr);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}