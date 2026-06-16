#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(N^2),O(n)
vector<int> leader(vector<int> nums){
    int n = nums.size();
    vector<int> ans;
    for(int i =0;i<n;i++){
        bool leader = true;
        for(int j = i+1;j<n;j++){
            if(nums[j]>nums[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(nums[i]);
        }

    }
    return ans;
}

vector<int> l(vector<int> nums){
    int n = nums.size();
    vector<int> ans;
    if(nums.empty()) {
            return ans;
        }
    ans.push_back(nums[n-1]);
    int max = nums[n-1];
    for(int i =n-2;i>=0;i--){
        if (nums[i] > max) {
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


int main(){
    vector<int> arr = {4,7,1,0};
    vector<int> res = l(arr);
    for(int n : res){
        cout<<n<<" ";
    }
    return 0;
}