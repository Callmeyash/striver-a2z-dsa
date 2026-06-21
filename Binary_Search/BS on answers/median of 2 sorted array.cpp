#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//Time	Space
//O(log(min(n1,n2)))	O(1)
double mediancal(vector<int>& a,vector<int>& b){
    if(a.size()>b.size()) return mediancal(b,a);
    int n1 = a.size();
    int n2 = b.size();
    int left = (n1+n2+1)/2;
    int low = 0;
    int high = n1;
    while(low<=high){
        int cut1 = low + (high-low)/2;
        int cut2 = left-cut1;
        int l1 = (cut1==0)?INT_MIN:a[cut1-1];
        int l2 = (cut2==0)?INT_MIN:b[cut2-1];
        int r1 = (cut1==n1)?INT_MAX:a[cut1];
        int r2 = (cut2==n2)?INT_MAX:b[cut2];
        if(l1<=r2 && l2 <=r1){
            if((n1+n2)%2==0) return ((max(l1,l2)+min(r1,r2)) / 2.0);
            else return max(l1,l2);
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0;
}

int main(){
    vector<int> a = {1,3,4,7,10,12};
    vector<int> b = {2,3,6,15};
    cout<<mediancal(a,b);
    return 0;
}