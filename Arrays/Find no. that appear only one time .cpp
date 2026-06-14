#include<iostream>
#include<vector>

using namespace std;
// brute force , O(n^2) O(1)
int find(vector<int>& arr){
    int n = arr.size();
    for(int i =0;i<n;i++){
        int num = arr[i];
        int cnt = 0;
        for(int j =0;j<n;j++){
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1){
                return num;
            }
    }
    return -1;
}

// better approach , O(n)+O(n)+O(n) ,O(maxi+1)
int find1(vector<int>& arr){
    int n = arr.size();
    int maxi = arr[0];
    for(int i =0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }
    for (int i = 0; i < n; i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
    }

    return -1;
}

// optimal approach , O(n) ,O(1)
int find2(vector<int>& arr){
    int n = arr.size();
    int xorr = 0;
    for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }

        return xorr;
    }

int main(){
    vector<int> arr = {1,1,2,3,3};
    cout<<find2(arr);
    return 0;
}