class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n), right(n);

        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans = (ans + (1LL * arr[i] * leftCount * rightCount) % MOD) % MOD;
        }

        return ans;
    }
};