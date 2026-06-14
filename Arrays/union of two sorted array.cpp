#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
//approach 1 O(m+n(log(m+n))) ,O(m+n)
vector<int> unionoftwosortedarray(vector<int> arr1,vector<int> arr2, int n, int m){
    map<int,int> freq;
    vector<int> Union;
    for(int i = 0;i<n;i++){
        freq[arr1[i]]++;
    }
    for(int i = 0;i<m;i++){
        freq[arr2[i]]++;
    }
    for(auto &it : freq){
        Union.push_back(it.first);
    }
    return Union;
}

//approach 2 O(m+n(log(m+n))) ,O(m+n)
vector<int> unionoftwosortedarray1(vector<int> arr1,vector<int> arr2, int n, int m){
    set<int> s;
    vector<int> Union;
    for(int i = 0;i<n;i++){
        s.insert(arr1[i]);
    }
    for(int i = 0;i<m;i++){
        s.insert(arr2[i]);
    }
    for(int it : s){
        Union.push_back(it);
    }
    return Union;
}

//approach 3 O(m+n) ,O(m+n)
vector<int> unionoftwosortedarray2(vector<int> arr1,vector<int> arr2, int n, int m){
    int i = 0;
    int j = 0;
    vector<int> Union;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(Union.empty() || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
                i++;
            }
        }
        else if(arr2[j]<arr1[i]){
            if(Union.empty() || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
                j++;
            }
        }
        else {
            if(Union.empty() || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
                i++,j++;
            }
        }
    }
    while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
    while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    
    
    return Union;
}

int main() {
    int n = 10;
    int m = 7;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2= {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = unionoftwosortedarray2(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}