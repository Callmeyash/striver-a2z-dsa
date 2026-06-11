//Reverse Digits of A Number

#include <iostream>
using namespace std;
int reverse(int n){
    int rev = 0;
    while(n>0){
        int lastdigit = n %10;
        rev = rev*10+lastdigit;
        n = n/10;
    }
    return rev;
}
int main() {
    // Write C++ code here
    cout<<reverse(5647);
    return 0;
}