#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//O(nlogn),O(n)
vector<vector<int>> intervalsmerge(vector<vector<int>>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    ans.push_back(nums[0]);
    for(int i = 1;i<n;i++){
        if(nums[i][0] <= ans.back()[1]){
        ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
        else{
            ans.push_back(nums[i]);
        }
    }
    return vector<vector<int>>(ans.begin(),ans.end());
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = intervalsmerge(arr);
    for(auto it : result){
        for(auto val : it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}