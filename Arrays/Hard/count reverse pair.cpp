#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
//O(2n*logn),O(n)
void merge(vector<int>& arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    long long cnt = 0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

long long countpair(vector<int>& arr,int low,int mid,int high){
    int right = mid+1;
    long long cnt = 0;
    for(int i=low ;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]) right++;
        cnt += (right -(mid+1));
    }
    return cnt;
}

long long mergesort(vector<int>& arr,int low,int high){
    long long cnt = 0;
    if(low>=high) return cnt;

    int mid = (low+high) / 2;

    cnt+= mergesort(arr,low,mid);
    cnt+= mergesort(arr,mid+1,high);
    cnt+= countpair(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

long long countreversepair(vector<int> &arr){
    return mergesort(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr = {3,2,1,4};
    cout<<countreversepair(arr);
    return 0;
}