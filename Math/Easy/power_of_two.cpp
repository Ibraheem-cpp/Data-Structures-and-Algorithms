#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
        if(n < 1) return false;

        while(n > 1){
            if(n % 2 != 0) return false;
            n = n/2;
        }

        return true;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    int n = 8;
    if(isPowerOfTwo(n)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}