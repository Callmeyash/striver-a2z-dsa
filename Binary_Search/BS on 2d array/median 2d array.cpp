#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(n log m × log(maxValue))
int mediancal(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i =0;i<n;i++){
        low = min(low,mat[i][0]);
        high = max(high,mat[i][m-1]);
    }
    int required = (n*m)/2;
    while(low<=high){
        int mid = low+(high-low)/2;
        int count =0;
        for(int i=0;i<n;i++){
            count += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        if(count<=required){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> arr = {{1 ,4 ,9 },{2 ,5, 6},{3, 8 ,7}};
    cout<<mediancal(arr);
    return 0;
}