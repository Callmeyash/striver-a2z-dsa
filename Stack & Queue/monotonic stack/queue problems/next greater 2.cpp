#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElements(vector<int>&arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int  i = 2*n-1;i>=0;i--){
            int current = arr[i%n];
            while(!st.empty() && st.top() <= current){
                 st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i] = st.top();
                }
            }
            st.push(current);  
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    Solution sol; 
    vector<int> ans = sol.nextGreaterElements(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < arr.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}