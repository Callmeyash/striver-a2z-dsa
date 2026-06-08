Binary Number Triangle Pattern

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Solution{
public:
    int printstar(int n){
        for(int i =1;i<=n;i++){
            int number = 1;
            if(i%2==0 ){number = 0;};
            for(int j=0;j<i;j++){
                cout<<number;
                number = 1-number;
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
