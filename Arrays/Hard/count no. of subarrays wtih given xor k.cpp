#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
//O(n^2),O(1)
int countxor(vector<int>& nums, int target){
    int n = nums.size();
    int cnt = 0;
    int xor = 0;
    for(int i =0;i<n;i++){
        xor = nums[i];
        if(xor== target){
                cnt++;
            }
        for(int j = i+1;j<n;j++){
            xor ^= nums[j];
            if(xor== target){
                cnt++;
            }
        }
    }
    return cnt;
}
//O(n),O(n)
int cntxor(vector<int>& nums, int target){
    unordered_map<int,int> mp;
    int n = nums.size();
    mp[0] = 1;
    int xor = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        xor ^= nums[i];
        int req = xor^target;
        if(mp.find(req)!=mp.end()){
            cnt += mp[req];
        }
        mp[xor]++;
    }
    return cnt;
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    cout<<cntxor(arr,6);
    return 0;
}