#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findlargest(vector<int>& arr){
    int n = arr.size();
    int largest = arr[0];
    for(int i =0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int findlargest1(vector<int>& arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}



int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<findlargest(arr);
    cout<<endl;
    cout<<findlargest1(arr);
    return 0;
}
