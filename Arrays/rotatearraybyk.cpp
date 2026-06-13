#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& arr,int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

vector<int> rotate(vector<int>& nums,int k,string direction){
    int n = nums.size();
        if (n == 0 || k == 0){ return nums;}
        k = k % n;
        if(direction == "right"){
            reverse(nums,0,n-1);
            reverse(nums,0,k-1);
            reverse(nums,k,n-1);
        }
        else if(direction == "left"){
            reverse(nums,0,k-1);
            reverse(nums,k,n-1);
            reverse(nums,0,n-1);
        }
        return nums;
}

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string dir = "right";

    vector<int> result = rotate(nums, k, dir);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}