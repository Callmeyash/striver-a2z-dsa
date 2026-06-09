Alpha-Ramp Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern16(int n) {
        for(int i = 0;i<n;i++){
            for(int j =0;j<i+1;j++){
                cout <<char('A' + i);
            }
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern16(4);
    return 0;
}