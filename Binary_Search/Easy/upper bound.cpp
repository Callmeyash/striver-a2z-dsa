#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(logn),O(1)
int upperbound(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    int ans  = n;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] > target){
            ans = mid;
            high = mid-1;
            }
            else low = mid + 1;                        
        }
        return ans;
 }

int main(){
    vector<int> arr = {1,2,2,3};
    cout<<upperbound(arr,2);
}