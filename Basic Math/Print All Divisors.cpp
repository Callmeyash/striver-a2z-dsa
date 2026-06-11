//O(n),O(sqrt(n))
#include<iostream>
#include<vector>
using namespace std;
/*int printDivisors(int n){
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            res.push_back(i);
        }
    }
    for(int divisor : res){
        cout<<divisor<<" ";
    }
    return 0;
}
*/

int printDivisors(int n){
    vector<int> res;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i){
                res.push_back(n/i);
            }
        }
    }
    for(int divisor : res){
        cout<<divisor<<" ";
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    printDivisors(n);
}