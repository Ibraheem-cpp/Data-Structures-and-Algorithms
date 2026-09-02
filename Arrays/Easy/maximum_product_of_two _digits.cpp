#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProduct(int n) {
        int largest = -1;
        int second_largest = -2;

        while(n > 0){
            int digit = n % 10;
            if(digit > largest){
                second_largest = largest;
                largest = digit;
            }
            else if(digit > second_largest && digit <= largest){
                second_largest = digit;
            }
            n /= 10;
        }

        return largest * second_largest;

        //      Time Complexity -> O(n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            10 <= n <= 10^9
    */

    int num = 26462;
    cout << maxProduct(num) << endl;

    return 0;
}