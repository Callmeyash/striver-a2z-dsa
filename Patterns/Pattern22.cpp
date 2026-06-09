Pattern - 22: The Number Pattern

#include <iostream>
using namespace std;
class Solution{
    public:
    void pattern22(int n){
        int size = 2 * n - 1; // Total rows and columns

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));
                cout << n - minDist << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    s.pattern22(4);
    return 0;
}