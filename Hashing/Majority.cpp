#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }
        return -1;
    }
};
int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}