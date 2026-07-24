#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long sumAndMultiply(int n) {
        long long int y = 0;
        int sum = 0;
        
        while(n > 0){
            int digit = n % 10;
            if(digit != 0){ 
                y = y * 10 + digit;
                sum += digit;
            }
            n /= 10;
        }

        long long int x = 0;
        while(y > 0){
            int digit = y % 10;
            x = x * 10 + digit;
            y /= 10;
        }

        return x * sum;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            0 <= n <= 10^9
    */

    long long int num = 306269002;
    cout << sumAndMultiply(num) << endl;

    return 0;
}