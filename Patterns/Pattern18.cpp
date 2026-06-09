Pattern-18: Alpha-Triangle Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern18(int n) {
        for(int i = 0;i<n;i++){
            char startChar = 'A' + (n-1 - i);
            for(int j =0;j<=i;j++){
                cout <<char(startChar+j);
            }
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern18(3);
    return 0;
}