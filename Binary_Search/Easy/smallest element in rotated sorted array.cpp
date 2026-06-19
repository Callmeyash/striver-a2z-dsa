#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(logn),O(1)
int searchelement(vector<int>& nums){
    int n = nums.size();
    int low  = 0;
    int high = n-1;
    while(low<high){
            int mid = (low + high) / 2; 
            if (nums[mid] > nums[high]){
            low = mid+1;
            }
            else high = mid;                        
        }
        return nums[low];
}

int main() {

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = searchelement(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}