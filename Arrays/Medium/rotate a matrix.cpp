#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//O(n^2),O(n^2)
vector<vector<int>> rotate(vector<vector<int>> matrix){
    int n = matrix.size();
    vector<vector<int>> result(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            result[j][n-i-1] = matrix[i][j];
        }
    }
   return result;
}
//O(n^2),O(1)
vector<vector<int>> rotate1(vector<vector<int>> matrix){
    int n = matrix.size();
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i =0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}
int main(){
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    vector<vector<int>> result = rotate1(arr);
    for(auto it : result){
        for(auto val : it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}