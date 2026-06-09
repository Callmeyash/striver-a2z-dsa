Increasing Letter Triangle Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern14(int n) {
        for(int i = 0;i<n;i++){
            for(int j =0;j<=i;j++){
                cout << char('A' + j);}
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern14(6);
    return 0;
}