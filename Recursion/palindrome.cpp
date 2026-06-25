#include<iostream>
using namespace std;

/*bool checkpalindrome(string a){
    for(int i =0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-1-i]){
            return false;
        }
    }
    return true;
}*/

/*bool checkpalindrome(string a,int start=0,int end=-1){
    if(end == -1){
        end = a.size() - 1;
    }
    if(start>end){
        return true;
    }
    if(a[start]!=a[end]){
        return false;
    }
    return checkpalindrome(a,start+1,end-1);
}
*/
bool checkpalindrome(string a,int start=0){
    if(start>=a.size()/2){
        return true;
    }
    if(a[start]!=a[a.size() - 1 - start]){
        return false;
    }
    return checkpalindrome(a,start+1);
}

int main(){
    string a = "1551";
    cout<<checkpalindrome(a);
    return 0;
}