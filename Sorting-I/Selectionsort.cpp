#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr = {5,3,2,4,1,6};
    selectionsort(arr);
    return 0;
}