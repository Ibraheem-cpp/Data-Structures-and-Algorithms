#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfSteps(int num) {
        int steps = 0;
        while(num >= 1){
            if(num % 2 == 0) num /= 2;
            else num -= 1;

            steps++;
        }

        return steps;

        //      Time Complexity -> O(log n)
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            0 <= num <= 10^6
    */

    int num = 3526;
    cout << numberOfSteps(num) << endl;

    return 0;
}