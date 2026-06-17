#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;
//O(n^4logn),O(2*n)
vector<vector<int>> foursum(vector<int>& arr,int target){
    int n = arr.size();
    set<vector<int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = i +1 ;j<n;j++){
            for(int k = j +1 ;k<n;k++){
                for(int l = k +1 ;k<n;k++){
                    int sum = arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum==target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}
//O(n^3logm),O(2*n)
vector<vector<int>> foursum1(vector<int>& arr,int target){
    int n = arr.size();
    set<vector<int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = i +1 ;j<n;j++){
            unordered_set<int> st;
            for(int k = j +1 ;k<n;k++){
                long long required = (long long)target - arr[i] - arr[j] - arr[k];
                if(st.count(required)){
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end()); //--m
                        ans.insert(temp);
                    }
                    st.insert(arr[k]);
                }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}
//O(n^3logn),O(m)
vector<vector<int>> foursum2(vector<int> & arr,int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i =0;i<n;i++){
        if(i>0 && arr[i]== arr[i-1]) continue;
        for(int j =i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int left = j+1,right = n-1;
            while(left<right){
                long long sum = (long long) arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target) {
                ans.push_back({arr[i], arr[j],arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1])
                        left++;
                    while (left < right && arr[right] == arr[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) left++;
                else right--;
        }
    }
}
return ans;
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = foursum2(arr, target);
    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}