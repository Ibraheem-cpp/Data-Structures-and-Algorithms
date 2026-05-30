#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int addDigits(int num) {

        int sum = 0;
        while(num > 0){
            int digit = num % 10;
            sum += digit;
            num = num / 10;
        }

        if(sum >= 10) sum = addDigits(sum);
        return sum;

        /*
            Time Complexity -> O(log n) : because the while loop will
                run for the number of digits each time and number of digits
                of any number is (log n) , the sum shrinks down at a high rate
                so only a few recursive calls will be made.
            Space Complexity -> O(log n) : because we are using recursion, call stack
                memory is used, if we use a while loop instead of recursion, the
                Space Complexity will become O(1)
        */
}

int main(){

    int num = 4567;
    cout << addDigits(num) << endl;

    return 0;
}