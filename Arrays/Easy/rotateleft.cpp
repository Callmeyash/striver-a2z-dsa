#include<iostream>
#include<vector>
using namespace std;

void rotateleft(vector<int>& arr){
    int n = arr.size();
    arr.push_back(arr[0]);
    arr.erase(arr.begin());
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    rotateleft(arr);
    for(int it : arr){
        cout<<it<<" ";
    }
    return 0;
}