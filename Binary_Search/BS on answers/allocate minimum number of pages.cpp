#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(nlog(sum(arr))),O(1)

int countStudent(vector<int>&arr,int pages){
    int student = 1;
    long long pagestudent = 0;
    for(int book : arr){
        if(book+pagestudent<=pages){
            pagestudent+=book;
        }else{
            student++;
            pagestudent = book;
        }
    }
    return student;
}
int allocate(vector<int>& arr,int student){
    if(arr.size()<student) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        long long mid = low + (high-low) /2;
        int st = countStudent(arr,mid);
        if(st<=student){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    cout<<allocate(arr,4);
}