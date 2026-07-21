#include<iostream>
#include<vector>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> factor;
    for(int i =2;i*i<=n;i++){
        while(n%i==0){
            factor.push_back(i);
            n/=i;
        }
    }
    if(n>1)
        factor.push_back(n);

    return factor;
}

vector<vector<int>> primeFactorization(vector<int>& queries){
    vector<vector<int>> ans;

    for(int x : queries){
        ans.push_back(primeFactors(x));
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    vector<vector<int>> res = primeFactorization(arr);
    for(auto x : res){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;

}