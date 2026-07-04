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

        for(int i=index;i<nums.size();i++){

            // Skip duplicates
            if(i>index && nums[i]==nums[i-1])
                continue;

            // Since array is sorted
            if(nums[i]>target)
                break;

            temp.push_back(nums[i]);

            solve(i+1,
                  target-nums[i],
                  nums,
                  temp,
                  ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums,
                                        int target){

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        vector<int> temp;

        solve(0,target,nums,temp,ans);

        return ans;
    }
};