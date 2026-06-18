#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
/*Complexity Analysis
Time Complexity: O(N+M), we traverse both the arrays exactly once.
Space Complexity: O(1), constant extra space is used to store pointers.
*/
void merge(vector<int>& num1,vector<int>& num2,int m,int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0){
        if(num2[j]>num1[i]){
            num1[k--] = num2[j--];
        }
        else{
            num1[k--] = num1[i--];
        }
    }
    while (j >= 0) {
            num1[k--] = num2[j--];
        }
}

int main(){
    vector<int> num1 = {-5,-2,4,5,0,0,0};
    vector<int> num2 = {-3,1,8};
    merge(num1,num2,4,3);
    for(int it:num1){
        cout<<it<<" ";
    }
    return 0;
}