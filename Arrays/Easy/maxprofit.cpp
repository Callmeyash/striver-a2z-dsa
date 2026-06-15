#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int price : prices){
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit,profit);
        }
    return maxProfit;
}
};
int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}