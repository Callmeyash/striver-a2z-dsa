#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*void reversearray(vector<int>& arr){
    int p1 =0;
    int p2 = arr.size()-1;
    while(p1<p2){
        swap(arr[p1],arr[p2]);
        p1++;
        p2--;
    }
}*/

/*void reversearray(vector<int>& arr){
    reverse(arr.begin(),arr.end());
}*/

void reversearray(vector<int>& arr,int n=0){
    if(n==arr.size()){
        return;
    }
    reversearray(arr,n+1);
    cout<<arr[n];
    cout<<endl;

}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reversearray(arr);
    return 0;
}