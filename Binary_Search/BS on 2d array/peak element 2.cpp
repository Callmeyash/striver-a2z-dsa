#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int rowmax(vector<vector<int>>& mat,int col){
    int n = mat.size();
    int row  = 0;
    for(int i =1;i<n;i++){
        if(mat[i][col]>mat[row][col]){
            row  = i;
        }
    }
    return row;
}

vector<int> peakelement2d(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;
    while(low<=high){
        int mid = low + (high-low) /2;
        int row = rowmax(mat,mid);
        int left = (mid-1>=0)?mat[row][mid-1]:-1;
        int right = (mid+1<m)?mat[row][mid+1]:-1;
        int cur = mat[row][mid];
        if(left<cur && right<cur) return {row,mid};
        else if (right>cur) low = mid+1;
        else high = mid-1;
    }
    return {-1,-1};
}

int main() {
      vector<vector<int>> mat = {
          {5,10,8},
          {4,25,7},
          {3,9,6}
      };
      vector<int> peak = peakelement2d(mat);
      cout << peak[0]<<","<< peak[1] << endl;
  
      return 0;
  }