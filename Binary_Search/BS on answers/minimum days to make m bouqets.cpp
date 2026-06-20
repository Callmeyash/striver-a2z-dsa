#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), Space Complexity : O(h)O(1)
int possible(vector<int> arr,int day,int b,int f){
    int n = arr.size();
    int bouqets  = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
            if(cnt==f){
                bouqets++;
                cnt = 0;
            }
        }
        else{
            cnt = 0;
        }
    }
    return bouqets;
    
}

int calculatebouquets(vector<int> arr,int b, int f){
    int total = 1LL*b*f;
    if(total>arr.size()) return -1;
    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());
    int result = -1;
    while(low<=high){
        int mid = low + (high-low) /2;
        int wemake = possible(arr,mid,b,f);
        if(wemake>=b){
            result = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    cout<<calculatebouquets(arr,2,3);
    return 0;
}