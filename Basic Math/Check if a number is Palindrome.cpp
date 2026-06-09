Check if a number is Palindrome or Not

#include <iostream>
using namespace std;
bool check_palindrome(int n){
    int original = n;
    int rev = 0;

    while (n > 0) {
        int lastdigit = n % 10;
        rev = rev * 10 + lastdigit;
        n /= 10;
    }
if (rev == original) {
        return true; 
    } else {
        return false; 
    }
}
int main() {
    int n = 5665;
    // Write C++ code here
    if (check_palindrome(n)) { 
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }

    return 0;
}