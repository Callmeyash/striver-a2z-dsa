#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:

    long long sumMin(vector<int>& nums){

        int n = nums.size();

        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller Element
        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){

            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans += 1LL * nums[i] * left * right;
        }

        return ans;
    }

    long long sumMax(vector<int>& nums){

        int n = nums.size();

        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater Element
        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Greater Element
        for(int i = n - 1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){

            long long left = i - pge[i];
            long long right = nge[i] - i;

            ans += 1LL * nums[i] * left * right;
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {

        return sumMax(nums) - sumMin(nums);
    }
};