#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(logn),O(1)
int findfloor(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    int ans  = n;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] <= target){
            ans = mid;
            low = mid+1;
            }
            else high = mid - 1;                        
        }
        return ans;
 }
 
 int findceiling(vector<int>& nums,int target){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    int ans  = n;
    while(low<=high){
            int mid = (low + high) / 2; 
            if (nums[mid] >= target){
            ans = mid;
            high = mid-1;
            }
            else low = mid + 1;                        
        }
        return ans;
 }

pair<int, int> getFloorAndCeil(vector<int> arr, int x) {
        int f = findfloor(arr, x);
        int c = findceiling(arr,x);
        return make_pair(f, c);
    }

 int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;

 }