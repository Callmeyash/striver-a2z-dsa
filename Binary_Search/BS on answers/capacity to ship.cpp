#include<iostream>
#include<vector>
#include<algorithm>
#include<math>
using namespace std;
//Time Complexity: O(N * log(S))
class Solution {
public:
    int countdays(vector<int>& arr,int cnt){
        int days  = 1;
        int currentload = 0;
        for(int wt :arr){
            if(wt+currentload>cnt){
                days++;
                currentload = wt;
            }
            else{
                currentload += wt;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid = low + (high-low)/2;
            int find = countdays(weights,mid);
            if(find<=days){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};