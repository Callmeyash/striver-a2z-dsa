#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(logn),O(1)
int countrotation(vector<int>& nums){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    while(low<high){
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]){
            low = mid+1;
            }
            else high = mid;                        
        }
        return low;
}

int main() {

    vector<int> nums = {1,2,3,4,5};

    int result = countrotation(nums);
    cout << "Rotated " << result <<" Times"<< endl;

    return 0;
}