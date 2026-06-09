Pattern - 20: Symmetric-Butterfly Pattern

#include <iostream>
using namespace std;
class Solution{
    public:
    void pattern20(int n){
        int space = 2*n-2;
        for(int i = 1 ;i<=2*n-1;i++){
            int stars = i;
            if(i>n) stars = 2*n -i;
            for(int j =1;j<=stars;j++){
                cout<<"*";
            }
            for(int j =1;j<=space;j++){
                cout<<" ";}
            for(int j =1;j<=stars;j++){
                cout<<"*";
            }
            cout<<endl;
            if(i<n) space -=2;
            else space +=2;
        }
    }
};
int main() {
    Solution s;
    s.pattern20(5);
    return 0;
}