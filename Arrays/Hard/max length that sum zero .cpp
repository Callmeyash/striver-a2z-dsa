#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n),O(n)
int maxlength(vector<int>& arr){
    int n = arr.size();
    int maxlen = 0;
    unordered_map<int,int> mp;//mapping sum to index
    int sum =0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
        if(sum==0){
            maxlen = i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            maxlen = max(maxlen,i-mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return maxlen;
}



int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << maxlength(a) << endl;
    return 0;
}