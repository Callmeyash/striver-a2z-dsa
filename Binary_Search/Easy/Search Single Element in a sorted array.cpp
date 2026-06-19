#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(logn),O(1)
int findunique(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1]; 
    int low  = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high) /2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
        if((mid%2==0 && nums[mid]==nums[mid+1])|| (mid%2==1 && nums[mid]==nums[mid-1])){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
    
}

int findunique1(vector<int>& nums){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    while(low<high){
        int mid = (low+high) /2;
        if(nums[mid]==nums[mid^1]) low = mid+1;
        else high = mid;
    }
    return nums[low];
    
}

int main() {

    vector<int> nums = {1,1,2,2,3,3,4,5,5,6,6};

    int result = findunique1(nums);
    cout <<result;

    return 0;
}