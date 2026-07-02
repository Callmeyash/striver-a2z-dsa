#include<iostream>
#include<string>
#include<vector>
using namespace std;

int countSubsequences(int i,int sum,int k,vector<int>&arr){
    if(i==arr.size()){
        return sum==k?1:0;
    }
    int left = countSubsequences(i+1,sum+arr[i],k,arr);
    int right = countSubsequences(i+1,sum,k,arr);
    return left+right;
}

int countsubsequenceswithsumk(vector<int>&arr,int k){
    return countSubsequences(0,0,k,arr);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countsubsequenceswithsumk(arr,k)<<endl;
    return 0;
}