Reverse Letter Triangle Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern15(int n) {
        for(int i = 0;i<n;i++){
            for(int j =0;j<n-i;j++){
                cout << char('A' + j);}
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern15(3);
    return 0;
}