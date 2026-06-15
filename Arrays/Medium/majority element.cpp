#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n^2),O(n)
int majorityelement(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j =0;j<n;j++){
            if (arr[j] == arr[i]) {
                    cnt++;
                }
            }
            if (cnt > (n / 2)) {
                return arr[i]; 
            }
        }
        return -1; 
 }
//O(n),O(n)
int majorityelelementhash(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int num : arr){
        mp[num]++;
    }
    for(auto &p :mp ){
        if(p.second > n/2){
            return p.first;
        }
    }
    return -1;
}
//O(n),O(1)
int majorityelement1(vector<int>& arr){
    int n = arr.size();
    int cnt = 0 ;
    int el ;
    for(int i =0;i<n;i++){
        if(cnt == 0){
            cnt++;
            el = arr[i];
        }
        else if(el==arr[i]){
            cnt++;
        }
        else {
            cnt--;
        }}
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == el) {
                cnt1++;
            }
        }
        if(cnt1 > n/2){
            return el;
        }

    return -1;
}

int main(){
    vector<int> arr = {1,1,7,7,7,7,2};
    cout<<majorityelement1(arr);
    return 0;
}