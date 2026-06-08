 Inverted Numbered Right Pyramid

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Solution{
public:
    int printstar(int n){
        for(int i =1;i<=n;i++){
            for(int j = n;j>=i;j--){
                cout<<n-j+1;
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
