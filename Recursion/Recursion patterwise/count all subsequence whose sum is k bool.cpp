#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool countSubsequences(int i,int sum,int k,vector<int>&arr){
    if(i==arr.size()){
        return sum==k;
    }
    if(countSubsequences(i+1,sum+arr[i],k,arr)) return true;
    return countSubsequences(i+1,sum,k,arr);
}

bool countsubsequenceswithsumk(vector<int>&arr,int k){
    return countSubsequences(0,0,k,arr);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<(countsubsequenceswithsumk(arr,k)?"Yes":"No")<<endl;
    return 0;
}