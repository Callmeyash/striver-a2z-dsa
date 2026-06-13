#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checksorted(vector<int>& arr){
    int i =0;
    int n = arr.size();
    if(n == 0 || n == 1)
        return true;
    for(int i = 1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
}
return true;
}

int main(){
    vector<int> arr = {1,1,2,6,4,5};
    cout<<checksorted(arr);
    return 0;
}