Increasing Number Triangle Pattern

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern13(int n) {
        int num = 1;
        for(int i = 1;i<=(n/2);i++){
            for(int j =1;j<=i;j++){
                cout<<num<<"";
                num =num +1;
            }
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern13(6);
    return 0;
}