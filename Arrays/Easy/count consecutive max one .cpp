#include<iostream>
#include<vector>

using namespace std;

int count(vector<int>& arr){
    int n = arr.size();
    int cnt = 0;
    int maxi = 0;
    for(int i =0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt = 0;
            }
    }
    return maxi;
}

int main(){
    vector<int> arr = {1,0,1,1,0,1,1,1};
    cout<<count(arr);
    return 0;
}