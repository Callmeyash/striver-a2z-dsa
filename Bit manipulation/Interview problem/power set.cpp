#include<iostream>
#include<vector>
using namespace std;
//O(Nx2^N)
void powerset(vector<int>&arr){
    int n = arr.size();
    for(int mask =0;mask<(1<<n);mask++){
        cout<< "{";
        for(int j = 0;j<n;j++){
            if(mask & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    vector<int> arr = {1,2,3};
    powerset(arr);
}