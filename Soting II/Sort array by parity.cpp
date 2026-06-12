#include<iostream>
#include<vector>
using namespace std;
  
/*void sortEvenOdd(vector<int>& arr) {
    vector<int> evens;
    vector<int> odds;

    for (int num : arr) {
        if (num % 2 == 0)
            evens.push_back(num);
        else
            odds.push_back(num);
    }

    arr.clear();
    arr.insert(arr.end(), evens.begin(), evens.end());
    arr.insert(arr.end(), odds.begin(), odds.end());

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
    */
    

    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0 ;
        int j = nums.size()-1;
        while(i<j){
            if(nums[i]%2==0){
                i++;
            }
            if(nums[j]%2==1){
                j--;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }


int main(){
    vector<int> arr = {3,1,2,4};
    sortArrayByParity(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}