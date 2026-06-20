#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Time Complexity: O(n * max(a[])),
int calculatetotalhours(vector<int> a,int h){
    int totalhour = 0;
    for(int pile:a){
        totalhour += (pile+h-1)/h;

    }
    return totalhour;
}
int calculate(vector<int> a,int h){
    int max_value = *max_element(a.begin(),a.end());
    for( int i = 1;i<=max_value;i++){
        int hours = calculatetotalhours(a,i);
        if(hours<=h){
            return i;
        }
    }
    return max_value;
}

//binary Time Complexity: O(N*log(max(a[]))) , Space O(n)
int calculatetotalhours1(vector<int>& a,int speed){
    int totalhour = 0;
    for(int banana:a){
        totalhour += ceil((double)banana/speed);

    }
    return totalhour;
}

int calculateb(vector<int> a, int h){
    int low  = 1;
    int high = *max_element(a.begin(),a.end());
    int ans = high;
    while(low<=high){
        int mid = low + (high-low) /2;
        int hours = calculatetotalhours1(a,mid);
        if(hours<=h){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {7, 15, 6, 3};
    cout<<calculateb(arr,8);
}