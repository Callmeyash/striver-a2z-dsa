#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//o(n^2),O(n)
int betterapproch(vector<int>& arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}
//O(n),O(1)
int kadanes_algo(vector<int>&arr ){
    int n = arr.size();
    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0;
    int maxstart = 0;
    int maxend = 0;
    for(int i =0;i<n;i++){
        if(sum ==0){
            start = i;
        }
        sum += arr[i];
        if(sum>maxi){
            maxi = sum;
            maxstart = start;
            maxend = i;
        }
        if(sum<0){
            sum = 0;
        }
    }
    for(int i =maxstart;i<=maxend;i++){
        cout <<arr[i]<<" ";
        
    }cout<<endl;
    return maxi;
}

int main(){
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout<<kadanes_algo(arr);
    return 0;
}