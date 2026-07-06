#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Time Complexity: O(2n),Each element has two choices: include or exclude, leading to 2n subsets. We directly compute sums without iterating over subsets, so complexity is O(2n). Sorting the sums adds O(2n log(2n)), making the total O(2n log(2n)).
//Space Complexity: O(2n),The result array holds all subset sums, requiring O(2n) space. Recursion uses an additional O(n) stack space due to function calls, so total auxiliary space is O(2n + n).
void solve(int ind,int sum,vector<int>& arr,vector<int>& ans){
    if(ind==arr.size()){
        ans.push_back(sum);
        return;
    }
    solve(ind+1,sum+arr[ind],arr,ans);
    solve(ind+1,sum,arr,ans);
}

vector<int> subsetsum(vector<int>& arr){
    vector<int> ans;
    solve(0,0,arr,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> arr={1,2,3};
    vector<int> ans = subsetsum(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}