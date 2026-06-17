#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//o(n^3),O(1)
int countsubarray(vector<int> nums,int target){
    int n = nums.size();
    int cnt = 0;
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            int sum = 0;
            for (int m = i; m <= j; m++) {
                    sum += nums[m];
                }
                if (sum == target) {
                    cnt++;
                }
            }
        }
    return cnt;
}
//O(n^2),O(1)
int countsubarray1(vector<int> nums,int target){
    int n = nums.size();
    int cnt = 0;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j =i;j<n;j++){
                    sum += nums[j];
                if (sum == target) {
                    cnt++;
                }
            }
            }
    return cnt;
}

int countsubarray2(vector<int> nums,int target){
    int n = nums.size();
    unordered_map<int,int> mp;
    int cnt = 0;
    int sum = 0;
    mp[0] = 1;
    for(int i =0;i<n;i++){
        sum += nums[i];
        int r = sum - target;
        if(mp.find(r) != mp.end()){
            cnt += mp[r];
        }
        mp[sum]++;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,1,3,1};
    int k = 4;
    cout<<countsubarray2(arr,k);
    return 0;
}