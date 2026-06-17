#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//o(n^3logn),O(2*n)
vector<vector<int>> sumthree(vector<int>& nums){
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
//o(n^3logn),O(2*n)
vector<vector<int>> sumthree1(vector<int>& nums){
    int n = nums.size();
    set<vector<int>> ans;
    for(int i = 0;i<n;i++){
        set<int> st;
        for(int j =i+1;j<n;j++){
            int third = -(nums[i]+nums[j]);
            if(st.find(third)!= st.end()){
                vector<int> temp = {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            st.insert(nums[j]);
        }
    }
    return vector<vector<int>>(ans.begin(),ans.end());
}
//O(n^2),O(n = ans)
vector<vector<int>> sumthree2(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left = i+1,right = n-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum==0){
                ans.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                
                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
            }
            else if(sum<0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sumthree2(arr);

    for (auto &triplet : res) {
        for (auto &num : triplet) cout << num << " ";
        cout << endl;
    }
    return 0;
}