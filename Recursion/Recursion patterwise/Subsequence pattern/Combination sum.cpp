#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int index,
               int target,
               vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans){

        if(target==0){

            ans.push_back(temp);

            return;
        }

        if(index==nums.size())
            return;

        // Pick
        if(nums[index]<=target){

            temp.push_back(nums[index]);

            solve(index,
                  target-nums[index],
                  nums,
                  temp,
                  ans);

            temp.pop_back();
        }

        // Don't Pick
        solve(index+1,
              target,
              nums,
              temp,
              ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> temp;
        solve(0,target,candidates,temp,ans);

        return ans;
    }
};