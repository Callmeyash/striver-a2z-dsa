#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(2*logn),O(1)
int firstoccurence(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    int ans  = -1;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] == target){
            ans = mid;
            high = mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }              
            else{
                high = mid-1;
            }         
        }
        return ans;
}
int lastoccurence(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    int ans  = -1;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] == target){
            ans = mid;
            low = mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }              
            else{
                low = mid+1;
            }         
        }
        return ans;
}

int countoccurence(vector<int>& arr,int t){
    int f = firstoccurence(arr,t);
    if(f == -1) return 0;
    int l = lastoccurence(arr,t);
    return l-f+1;
}
int main(){
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    cout<<countoccurence(arr,20);
}