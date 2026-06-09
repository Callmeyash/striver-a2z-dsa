Number Crown Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern12(int n) {
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=i;j++){
                cout<<j;
            }
            int space = 2 * (n - i);
            for (int j = 1 ; j<=space;j++){
                cout<<" ";
            }
            for(int j = i;j>=1;j--){
                cout<<j;
            }
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern12(3);
    return 0;
}