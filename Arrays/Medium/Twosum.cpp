#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n^2),O(1)
string twosum(vector<int>& arr,int target){
    int n = arr.size();
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(arr[i]+arr[j]==target && arr[j]!=arr[i]){
                return "Yes";
            }
        }
    }
    return "No";
}
//O(n),O(n)

vector<int> twosum1(vector<int>& arr,int target){
    int n = arr.size();
    unordered_map<int,int> mp;
    int r = 0;
    for(int i =0;i<n;i++){
        r = target - arr[i];
        if(mp.find(r)!=mp.end()){
            return {mp[r], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

//optimal approch O(nlogn),O(n)

vector<int> twosum2(vector<int>&arr,int target){
    int n = arr.size();
    vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
    sort(numsWithIndex.begin(),numsWithIndex.end());
    if (n < 2) return {-1, -1};
    int left = 0;
    int right = n-1;
    while(left<right){
        long long sum = (long long)numsWithIndex[left].first+numsWithIndex[right].first;
        if(sum<target){
            left++;
        }
        else if(sum>target){
           right--;
        }
        else{
            return {numsWithIndex[left].second,numsWithIndex[right].second};
        }
    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<twosum(arr,5);
    cout<<endl;
    vector<int> res = twosum2(arr, 6);
    cout << "[" << res[0] << ", " << res[1] << "]\n";
    return 0;
}