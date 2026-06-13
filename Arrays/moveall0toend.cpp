#include<iostream>
#include<vector>
using namespace std;
//brute force : O(n),o(n)
vector<int> move(vector<int>& arr){
    int n= arr.size();
    vector<int> temp(arr.size(), 0);
    int index = 0;
    for(int i =0;i<n;i++){
        if(arr[i]!=0){
            temp[index] = arr[i];
            index++;}
        }
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        return arr;
    }
//optimal approch : O(n),o(1)
void move1(vector<int>& arr){
    int n=arr.size();
    int j =-1;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
        }
    }
}
//worst case problem if array having only 0's
vector<int> move3(vector<int>& arr){
    int n= arr.size();
    if(n == 0 || n==1){
        return arr;
    }
    for(int i = 0; i<n;i++){
        if(arr[i]==0){
        arr.push_back(arr[i]);
        arr.erase(arr.begin()+i);
        }
    }
    return arr;
    
}
int main() {

    vector<int> nums = {1,2,0,0,0,4,0};
    move1(nums);
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}