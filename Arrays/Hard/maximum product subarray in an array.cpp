#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

int maximumproduct(vector<int>& arr){
    int n = arr.size();
    long long pp = 1;
    long long sp = 1;
    long long ans = INT_MIN;
    for(int i =0;i<n;i++){
        if(pp == 0) pp = 1;
        if(sp == 0) sp = 1;
        pp *= arr[i];
        sp *= arr[n-i-1];
        ans = max(ans,max(pp,sp));
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5,0};
    cout << maximumproduct(arr) << endl;

    return 0;
}