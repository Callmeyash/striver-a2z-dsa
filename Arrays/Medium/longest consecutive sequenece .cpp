#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;


bool longestsequence(vector<int>& arr,int x){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}
//O(n^2),O(1)
int longest(vector<int>& nums){
    if (nums.size() == 0) {
            return 0;
        }
    int n = nums.size();
    int longest = 1;
    for(int i =0;i<n;i++){
        int x = nums[i];
        int cnt = 1;
        while(longestsequence(nums,x) == true){
            cnt += 1;
            x += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}
//O(nlogn),O(1)
int longest1(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int longest = 1;
    int cnt = 1;
    int lastsmaller = INT_MIN;
    for(int i = 0;i<n;i++){
        if(nums[i] -1 == lastsmaller){
            cnt ++;
            lastsmaller = nums[i];
        }
        else if (nums[i] - 1 != lastsmaller){
            cnt = 1;
            lastsmaller = nums[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}
//O(n),O(n)
int longest2(vector<int>& nums){
    int  n = nums.size();
    int longest = 1;
    unordered_set<int> st;
    for(int i =0;i<n;i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
        
        while(st.find(x+1) != st.end()){
            x = x + 1;
            cnt ++;
        }
        longest = max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout<<longest2(arr);
    return 0;
}