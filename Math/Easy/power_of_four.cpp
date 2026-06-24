#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
        if(n == 1) return true;

        while(n > 4){
            if(n % 4 != 0) return false;
            n = n/4;
        }

        if(n < 4) return false;
        return true;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    int n = 64;
    if(isPowerOfFour(n)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}