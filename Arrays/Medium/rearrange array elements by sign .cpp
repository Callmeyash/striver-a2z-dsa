#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//)(n/2+n),O(n/2+n/2)
vector<int> rearrange(vector<int>& nums){
    int n = nums.size();
    vector<int> neg;
    vector<int> pos; 
    for(int num : nums){
        if(num<0){
            neg.push_back(num);
        }
        if(num>0){
            pos.push_back(num);
        }
    }
    for (int i = 0; i < n / 2; i++) {
            nums[2 * i] = pos[i];     
            nums[2 * i + 1] = neg[i];  
    }
    return {nums};
}
//o(n),o(1)
vector<int> rearrange1(vector<int>& nums){
    int n = nums.size();
    int left =0, right = n-1;
    while(left<right){
        if(nums[left]>=0 && left%2==0 || nums[left] < 0 && left % 2 == 1){
            left++;
        }
        else if (nums[right] >= 0 && right % 2 == 0 || nums[right] < 0 && right % 2 == 1) {
            right--;
        }
        else{
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    return nums;
}

int main(){
    vector<int> arr = {1,2,-4,-5};
    rearrange1(arr);
    for(int num : arr){
        cout<<num<<" ";
    }
}

