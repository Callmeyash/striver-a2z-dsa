#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//O(n^2),O(n^2) -- full pascal triangle
vector<vector<int>> pascaltriangle(int n ){
    vector<vector<int>> triangle;
    for(int i =0;i<n;i++){
        vector<int> row(i+1,1);
        for(int j= 1;j<i;j++){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}
//o(n),O(n)-- nth row
vector<long long> pascaltriangle1(int n ){
    vector<long long> result;
    long long val = 1;
    result.push_back(val);
    for(int i = 1;i<n;i++){
        val = val * (n-i)/i;
        result.push_back(val);
    }
    return result;
}
//O(min(c,r-c)),O(1) -- element at (r,c)
long long pascaltriangle2(int r,int c){
    int n = r-1;
    int k = c-1;
    long long result = 1;
    for(int i = 0;i<k;i++){
        result *= n-i;
        result /= i+1;
    }
    return result;
}
int main(){
    cout<<pascaltriangle2(5,3);
    /*vector<long long> result =  pascaltriangle1(5);
    for(auto  num : result ){
            cout << num <<" ";        
    }*/
    return 0;
    
}