#include<iostream>
#include<vector>
using namespace std;
//Time: O(N)
//Space: O(1)
int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int num : nums){
        ans ^= num;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4};
    cout<<singleNumber(arr);
}