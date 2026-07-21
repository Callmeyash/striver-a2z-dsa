#include<iostream>
#include<vector>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> ans;
    for(int i =2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n /=i;
        }
    }
    if(n>1){
        ans.push_back(n);
    }
    return ans;
}

int main(){
    vector<int> res = primeFactors(12);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}