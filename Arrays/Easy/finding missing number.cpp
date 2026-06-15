#include<iostream>
#include<vector>

using namespace std;
//Linear Search for Missing Number - O(n^2) Time and O(1) Space
int find(vector<int>& arr){
    int n = arr.size();
    for(int i = 1 ;i<=n;i++){
        bool found = false;
        for(int j =0;j<n;j++){
            if(arr[j]==i){
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return -1;
}

//Using Hashing - O(n) Time and O(n) Space

int find1(vector<int>& arr){
    int n = arr.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i<n ;i++){
        hash[arr[i]]++;
    } 
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}

//Using Sum of n terms Formula - O(n) Time and O(1) Space
int find2(vector<int>& arr){
    int n = arr.size()+1;
    int sum = 0;
    for(int i =0;i<n-1;i++){
        sum+= arr[i];
    }
    long long expSum = (n *1LL* (n + 1)) / 2;

    return expSum - sum;
}


int main() {
    vector<int> arr = {6,5,3,2,1}; 
    cout << find1(arr) << endl; 
    return 0;
}