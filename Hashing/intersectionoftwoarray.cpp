#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        mp[nums1[i]]++;
    }
    for(int i=0;i<nums2.size();i++){
        if(mp[nums2[i]] > 0){
            ans.push_back(nums2[i]);
            mp[nums2[i]]--;
        }

    }
    return ans;
}
int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersection(nums1, nums2);
    cout << "Intersection of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}