#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr,int low ,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>= low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(vector<int>& arr,int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex -1);
        qs(arr,pIndex+1,high);
    }
}

vector<int> quicksort(vector<int>& arr,int n){
    qs(arr,0,n-1);
    return arr;
}
int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    quicksort(arr, arr.size());
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}