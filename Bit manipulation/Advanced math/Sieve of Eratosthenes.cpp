#include<iostream>
#include<vector>
using namespace std;

vector<int> primeQuery(vector<vector<int>>& queries){
    int maxi = 0;
    for(auto q : queries){
        maxi = max(maxi,q[1]);
    }
    vector<bool> prime(maxi+1,true);
    prime[0] = false;
    prime[1] = false;

    for(int i =2;i*i<=maxi;i++){
        if(prime[i]){
            for(int j = i*i;j<=maxi;j+=i){
                prime[j] = false;
            }
        }
    }
    vector<int> prefix(maxi+1,0);
    for(int i=1;i<=maxi;i++){
        prefix[i] = prefix[i-1]+prime[i];
    }
    vector<int> ans;
    for(auto q : queries){
        int L = q[0];
        int R = q[1];
        if(L == 0){
            ans.push_back(prefix[R]);
        }
        else{
            ans.push_back(prefix[R]-prefix[L-1]);
        }
    }
    return ans;
}