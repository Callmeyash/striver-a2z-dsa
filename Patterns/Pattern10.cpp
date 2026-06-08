 Half Diamond Star Pattern

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Solution{
public:
    int printstar(int n){
        for(int i =1;i<2*n-1;i++){
            int star = i;
            if(i>n){ star = 2*n-i;}
            for(int j=0;j<star;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        return 0;
    }
};
int main() {
    Solution s;
    s.printstar(6);
    return 0;
}
