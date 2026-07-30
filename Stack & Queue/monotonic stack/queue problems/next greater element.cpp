#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>& A){
        int n = A.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top()<=A[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]= -1;
            }
            else{
                ans[i]= st.top();
            }
            st.push(A[i]);
        }
        return ans;
    }
};

int main(){
    Solution st;
    vector<int> arr = {5,6,4,9,10};
    vector<int> res = st.nextGreaterElement(arr);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}