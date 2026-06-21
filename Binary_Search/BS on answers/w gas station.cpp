#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int countstation(vector<int>& arr, double dist){
    int cnt  = 0;
    for(int i =1;i<arr.size();i++){
        double gap = arr[i] - arr[i-1];
        int needed = gap/dist;
        if(gap==needed*dist){
            needed--;
        }
        cnt += needed;
    }
    return cnt;
}

double minimizemaxdist(vector<int>&arr,int k){
    double low = 0;
    double high = 0;
    for(int i =1;i<arr.size();i++){
        high = max(high, (double)(arr[i] - arr[i-1]));
        }
    while(high-low> 1e-6){
        double mid = low +(high-low)/2.0;
        int cnt = countstation(arr, mid);
        if(cnt<=k){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return high;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimizemaxdist(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}

