#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(n log n + n log(maxDist))
bool countdistance(vector<int>& arr,int cows,int k){
    int count = 1;
    int last = arr[0];
    for(int i =1;i<arr.size();i++){
        if(arr[i]-last>=k){
            count++;
            last = arr[i];
        }
        if(count>=cows) return true;
    }
    return false;
}
int distance(vector<int>& arr,int cows){
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr.back() - arr.front();
    int ans =0;
    while(low<=high){
        long long mid = low +(high-low) /2;
        if(countdistance(arr,cows,mid)){
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {0,3,4,7,10,9};
    cout<<distance(arr,4);
    return 0;
}