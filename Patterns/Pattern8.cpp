Star Pyramid

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Solution{
public:
    int printstar(int n){
        for(int i =0;i<n;i++){
            for(int j = 0;j<n-i-1;j++){
                cout<<" ";
            }
            for(int j = 0;j<2*i-1;j++){
                cout<<"*";
            }
            for(int j = 0;j<n-i-1;j++){
                cout<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};
int main() {
    Solution s;
    s.printstar(3);
    return 0;
}
