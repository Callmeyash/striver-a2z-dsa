Pattern - 21: Hollow Rectangle Pattern

#include <iostream>
using namespace std;
class Solution{
    public:
    void pattern21(int n){
        for(int i =0;i<n;i++){
              for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
           cout<<endl;
        }
    }
};
int main() {
    Solution s;
    s.pattern21(4);
    return 0;
}