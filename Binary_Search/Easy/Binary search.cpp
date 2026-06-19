#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarysearch(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] == target) return mid;       
            else if (target > nums[mid]) low = mid + 1; 
            else high = mid - 1;                        
        }
        return -1;
 }
//Recursive method O(logn),O(1)

int binarysearch1(vector<int> & arr,int low,int high,int target){
    if(low>high) return -1;

    int mid = (low+high)/2;
    if(arr[mid]==target) return mid;
    else if(target>arr[mid]) return binarysearch1(arr,mid+1,high,target);
    
    return binarysearch1(arr,low,mid-1,target);
}
int search(vector<int>& nums, int target) {
        return binarysearch1(nums, 0, nums.size() - 1, target);
}


 int main(){
    vector<int> arr = {1,2,3,4,5,6};
    cout<<search(arr,6);
    return 0;
 }