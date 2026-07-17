#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumber(vector<int>&nums){
    int xorALL = 0;
    for(int x:nums){
        xorALL ^= x;
    }

    int rightmost = xorALL & (-xorALL);
    int a =0,b=0;
    for(int x : nums){
        if(x & rightmost){
            a ^=x;
        }
        else{
            b ^=x;
        }
    }
    if(a>b){
        swap(a,b);
    }
    return {a,b};
}

int main(){
    vector<int> arr = {1,2,2,3,3,4,5,5};
    vector<int> res = singleNumber(arr);
    for(int a : res){
        cout<<a<<" ";
    }
    return 0;
}