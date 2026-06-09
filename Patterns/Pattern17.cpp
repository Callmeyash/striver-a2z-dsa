Pattern - 17: Alpha-Hill Pattern ( important)

#include <iostream>
using namespace std;
class Solution {
public:
    void pattern17(int n) {

        for(int i = 0;i<n;i++){
            for(int j =0;j<n-i-1;j++){
                cout <<" ";
            }
            char ch = 'A';
            int breakpoint = (2 * i + 1) / 2;
            for(int j = 0;j<2*i+1;j++){
                cout<<ch;
                if(j<(2 * i + 1) / 2 ){
                ch++;
                }else {ch--;
                }
            }
            for(int j =0;j<n-i-1;j++){
                cout <<" ";
            }
            cout<<endl;
        }

    }
};
int main() {
    Solution s;
    s.pattern17(3);
    return 0;
}