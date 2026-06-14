#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int removeo(vector<int>& arr){
    if(arr.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < arr.size(); j++) {
            if(arr[j] != arr[i]) {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;
    }

void remove(vector<int>& arr){
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]){
            arr.erase(arr.begin()+i);
        }
    }
    for(int nums : arr){
        cout<<nums<<" ";
    }
}

void remove1(vector<int>& arr){
    unordered_set<int> s(arr.begin(), arr.end());
    for(auto it : s){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> arr = {1,1,2,2,3,4};

    remove1(arr);
    return 0;
}