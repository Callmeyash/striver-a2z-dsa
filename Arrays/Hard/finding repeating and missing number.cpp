#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
//O(n^2),O(1)
vector<int> finding(vector<int> arr){
    int n = arr.size();
    int m = -1;
    int c = -1;
    for(int i =1;i<=n;i++){
        int cnt = 0;
        for(int j =0;j<n;j++){
            if(arr[j]==i){
                cnt++;
            }
        }
        if (cnt == 2) c = i;
            else if (cnt == 0) m = i;

            if (c != -1 && m != -1)
                break;
        }
        return {c,m};
}
//O(n),O(n)
vector<int> finding1(vector<int>& arr){
    int n=arr.size();
    unordered_map<int,int> mp(n+1);
    for(int i = 0;i<n;i++){
        mp[arr[i]]++;
    }
    int d = -1;
    int m = -1; 
    for(int i =0;i<=n;i++){
        if(mp[i]==2){
            d=i;
        }
        if(mp[i]==0){
            m=i;
        }
    }
    return {d,m};

}
//math approach )O(n),O(1)
vector<int> findingo(vector<int>& arr){
    int n = arr.size();
    long long asum = 0;
    long long asq = 0;
    for(int num : arr){
        asum += num;
        asq += 1LL * num * num;
    }
    long long esum =
        (1LL * n * (n + 1)) / 2;
    long long esq =
        (1LL * n * (n + 1) * (2 * n + 1)) / 6;
    long long val1 = asum - esum; // x - y
    long long val2 = asq - esq;   // x² - y²
    long long val3 = val2 / val1; // x + y
    long long x = (val1 + val3) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}
//XOR IMPORTANT
vector<int> findingox(vector<int>& nums){
    int n = nums.size();
    int xor = 0;
    for (int i = 0; i < n; i++) {
        xor ^=nums[i];
        xor ^=(i+1);
    }
    int number = (xor & ~(xor-1));
    int one = 0;
    int zero =0;
    for(int i =0;i<n;i++){
        if((nums[i] & number) != 0){
            one ^= nums[i];
        }
        else{
            zero ^= nums[i];
        }
    }
    for(int i = 1;i<=n;i++){
        if((i & number) != 0){
            one ^= i;
        }
        else{
            zero ^= i;
        }
    }
    int cnt = 0;
    for(int i =0;i<n;i++){
        if(nums[i]==zero){
            cnt++;
        }
    }
    if(cnt == 2){
        return {zero,one};
    }
    return {one,zero};
}

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};

    vector<int> result = findingox(nums);
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
