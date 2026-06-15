#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n),O(1)
void sortZeroOneTwo(vector<int>& arr){
    int n = arr.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt0 = 0;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    int index = 0;
    while(cnt0--){
        arr[index++] = 0;
    }
    while(cnt1--){
        arr[index++] = 1;
    }
    while(cnt2--){
        arr[index++] = 2;
    }
}

void sortZeroOneTwo1(vector<int>& arr){
    int n = arr.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt0 = 0;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    
    for(int i =0;i<cnt0;i++){
        arr[i] = 0;
    }
     for(int i =cnt0;i<cnt0+cnt1;i++){
        arr[i] = 1;
    }
     for(int i =cnt0+cnt1;i<n;i++){
        arr[i] = 2;
    }
}

void DutchNationalFlagAlgo(vector<int>& arr){
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high= n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {1, 0, 2, 1, 0};
    DutchNationalFlagAlgo(nums);

    for(int x : nums) {
        cout << x << " ";
    }

    return 0;
}

