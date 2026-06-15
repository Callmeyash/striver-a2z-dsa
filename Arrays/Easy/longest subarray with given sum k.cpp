#include<iostream>
#include<vector>

using namespace std;
//O(n^3) , O (1)
int longestsubarray(vector<int> & arr,int k ){
    int n = arr.size();
    int maxlength = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int currentSum = 0;
                for (int k = i; k <= j; i++) {
                    currentSum += arr[k];
                }

                if (currentSum == k)
                    maxlength = max(maxlength, j - i + 1);
        }
    }
    return maxlength;
}
//O(n),O(1)
int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int maxLen = 0;
        int left = 0, right = 0;
        int sum = nums[0];

        while(right < n) {

            while(left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }
            if(sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            
            right++;
            if(right < n) sum += nums[right];
        }
        
        return maxLen;
    }

int main()
{
    vector<int> a = { -1, 1, 1 };
    int k = 1;
    int len = longestSubarray(a, k);
    
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
