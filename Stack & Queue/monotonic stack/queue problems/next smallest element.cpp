#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> nextSmallerElement(vector<int>&arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top() >=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

int main(){
    Solution st;
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> res = st.nextSmallerElement(arr);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}