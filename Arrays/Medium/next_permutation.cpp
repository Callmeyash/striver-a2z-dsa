#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(n!n),O(n!)
vector<int> nextpermutation(vector<int> nums){
    vector<vector<int>> all;
    vector<int> temp(nums);
    sort(temp.begin(),temp.end());
    do{
        all.push_back(temp);
    }while(next_permutation(temp.begin(),temp.end()));
    for(int i = 0;i<all.size();i++){
        if(all[i] == nums){
            if(i == all.size() - 1){
                return all[0];
            }
            return all[i + 1];
        }
    }
    return nums;
}
//O(n),O(1)
void np(vector<int> nums){
    int n = nums.size();
    int index = -1;
    for(int i = n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(nums.begin(), nums.end());
            return;
        }
    for(int i = n-1; i>index ;i--){
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index +1,nums.end());
}

int main(){
    vector<int> arr ={1,3,2};
    vector<int> result = nextpermutation(arr);
    for (int x : result) cout << x << " ";
    cout << endl;
    np(arr);
    for(int n : arr){
        cout<<n<<" ";
    }

    return 0;
}