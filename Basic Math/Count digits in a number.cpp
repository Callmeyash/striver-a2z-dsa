Count digits in a number

#include <iostream>
using namespace std;
int counter(int n){
    int c = 0;
    while(n>0){
        c++;
        n /= 10;
    }
    return c;
}

#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int counter(int n){
    int cnt = (int)(log10(n)+1);

    return cnt;
}
int main() {
    // Write C++ code here
    cout<<counter(5647);
    return 0;
}