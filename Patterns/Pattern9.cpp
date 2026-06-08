Inverted Star Pyramid

#include <iostream>
using namespace std;
class Solution{
public:
    int printstar(int n){
        for(int i =0;i<n;i++){
            for(int j = 0;j<i;j++){
                cout<<" ";
            }
            for(int j = 0;j<(2*n)-(2*i+1);j++){
                cout<<"*";
            }
            for(int j = 0;j<i;j++){
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
