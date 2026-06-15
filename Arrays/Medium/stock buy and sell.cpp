#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n^2),O(1)
int maxprofit(vector<int>& arr){
    int n = arr.size();
    int maxi = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int profit = arr[j] - arr[i];
            maxi = max(profit,maxi);
        }
    }
    return maxi;
}
//O(n),O(1)
int maxprofitday(vector<int>& nums){
    int n = nums.size();
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int price : nums){
        if(price < minprice){
            minprice = price;
        }
        else{
        maxprofit = max(maxprofit,price - minprice);
        }
    }
    return maxprofit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxprofitday(prices);
    return 0;
}