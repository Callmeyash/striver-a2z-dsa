#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findsecondsandl(vector<int>& arr){
    int n = arr.size();
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;
    sort(arr.begin(),arr.end());
    cout << "Second smallest is " <<arr[1]<< endl;
    cout << "Second largest is " <<arr[n-2]<< endl;
    return 0;
}
//better
int findsecondsandl1(vector<int>& arr){
    int n = arr.size();
    int s = INT_MAX;
    int l = INT_MIN;
    int ss = INT_MAX;
    int sl = INT_MIN;
    for(int i =0;i<n;i++){
        if(arr[i]<s){
            s = arr[i];
        }
        if(arr[i]>l){
            l = arr[i];
    }
}
    for(int i =0;i<n;i++){
            if(arr[i]<ss && arr[i]!=s){
            ss = arr[i];
        }
            if(arr[i]>sl && arr[i]!=l){
            sl = arr[i];
        }
    }
    cout << "Second smallest is " <<ss<< endl;
    cout << "Second largest is " <<sl<< endl;
    return 0;
}

//optimal
int findsecondsandl2(vector<int>& arr){
    int n = arr.size();
    int s = INT_MAX;
    int l = INT_MIN;
    int ss = INT_MAX;
    int sl = INT_MIN;
    for(int i =0;i<n;i++){
        if(arr[i]<s){
            ss = s;
            s = arr[i];}
        if(arr[i]<ss && arr[i]!=s){
            ss = arr[i];
        }
        if(arr[i]>l){
            sl = l;
            l = arr[i];
        }
        if(arr[i]>sl && arr[i]!=l){
            sl = arr[i];
        }
}
    cout << "Second smallest is " <<ss<< endl;
    cout << "Second largest is " <<sl<< endl;
    return 0;
}

int main(){
    vector<int> arr = {5,4,2,1,3};
    //findsecondsandl(arr);
    findsecondsandl1(arr);
    findsecondsandl2(arr);
    return 0;
}
