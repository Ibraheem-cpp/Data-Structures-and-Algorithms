#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
        if(n < 1) return false;

        while(n > 1){
            if(n % 3 != 0) return false;
            n = n/3;
        }

        return true;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    int n = 9;
    if(isPowerOfThree(n)) cout << "Yes.\n";
    else cout << "No.\n";

    return 0;
}