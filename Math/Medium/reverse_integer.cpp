#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool isNegative = true;
        if(x > 0) isNegative = false;
        x = abs(x);

        int temp = 0;
        while(x > 0){
            int digit = x % 10;
            if(temp > (INT_MAX - digit)/10) return 0;
            temp = (temp * 10) + digit;
            x /= 10;
        }

        if(isNegative) return temp * -1;
        return temp;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints
            -2^31 <= x <= 2^31 - 1
    */

    int num = 8327628;
    cout << reverse(num) << endl;

    return 0;
}