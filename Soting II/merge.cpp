#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int l,int mid,int h){
    vector<int> temp;
    int left = l;
    int right = mid+1;
    while(left<= mid && right <=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=h){
        temp.push_back(arr[right++]);
    }
    for(int i =l;i<=h;i++){
        arr[i] = temp[i-l];
    }
    
}
void ms(vector<int>& arr,int l,int h){
    if(l>=h){
        return;
    }
    int mid = (l+h)/2;
    ms(arr,l,mid);
    ms(arr,mid+1,h);
    merge(arr,l,mid,h);
}
void mergeSort(vector<int> & arr,int n){
    ms(arr,0,n-1);
}
 
int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    mergeSort(arr, arr.size());
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}