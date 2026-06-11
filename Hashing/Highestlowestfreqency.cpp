#include<iostream>
#include<unordered_map>
using namespace std;

void highorlowfreq(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int max_freq = 0;
    int min_freq = n; 
    int max_freq_element = 0;
    int min_freq_element = 0;
    for(auto it : mp){
        if(it.second > max_freq){
            max_freq = it.second;
            max_freq_element = it.first;
        }
        if(it.second < min_freq){
            min_freq = it.second;
            min_freq_element = it.first;
        }
        
    }
    cout << "Element with highest frequency: " << max_freq_element << endl;
    cout << "Element with lowest frequency: " << min_freq_element << endl;
}
int main(){
    int arr[] = {1, 2, 3, 4, 2, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    highorlowfreq(arr, n);
    return 0;
}