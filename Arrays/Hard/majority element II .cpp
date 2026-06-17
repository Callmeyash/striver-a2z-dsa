#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//O(n^2),O(1)
vector<int> majortiyelement(vector<int>& nums){
    int n = nums.size();
    vector<int> result;
    for(int i = 0;i<n;i++){
        if(result.size() == 0 ||result[0] != nums[i]){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt > (n/3)){
                result.push_back(nums[i]);
            }
        }
            if(result.size()==2) break;
     return result;   }
    
}
//O(nlogn),o(n)
vector<int> majortiyelement1(vector<int>& nums){
    vector<int> result;
    int n = nums.size();
    int mini = int(n/3)+1;
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        mp[nums[i]]++;
        if(mp[nums[i]]==mini){
            result.push_back(nums[i]);
        }
        if(result.size() == 2){
            break;
        }
    }
    return result;
}
//O(n),O(1) -- Boyer moore's voting algorithm
vector<int> majorityelement2(vector<int>& nums){
    int n = nums.size();
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;
    vector<int> result;
    for(int i =0;i<n;i++){
        if(cnt1 == 0 && nums[i]!=el2){
            el1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i]!=el1){
            el2 = nums[i];
            cnt2 = 1;
        }
        else if(nums[i]==el1){
            cnt1++;
        }
        else if(nums[i]==el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0,cnt2 = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]==el1){
            cnt1++;
        }
        if(nums[i]==el2){
            cnt2++;
        }
    }
    int mini = n/3 +1 ;
    if(cnt1==mini){
        result.push_back(el1);
    }
    if(cnt2==mini){
        result.push_back(el2);
    }
    return result;
}

int main(){
    vector<int> arr = {1, 2, 1, 1, 3, 2, 2};
    vector<int> ans = majorityelement2(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
}
