#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    public:
    int countGreater(vector<int> & arr, int idx){
        int count = 0;
        for(int i = idx+1;i<arr.size();i++){
            if(arr[i]>arr[idx]){
                count++;
            }
        }
        return count;
    }
    vector<int> count_NGEs(vector<int>&arr,vector<int>& queries){
        vector<int> ans;
        for(int idx : queries){
            ans.push_back(countGreater(arr,idx));
        }
        return ans;
    }
};

int main(){
    Solution st;
    vector<int> arr = {3,4,2,7,5};
    vector<int> queries = {0,1,2,3,4};
    vector<int> res = st.count_NGEs(arr,queries);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}