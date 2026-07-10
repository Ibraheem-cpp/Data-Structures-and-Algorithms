#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countOperations(int num1, int num2) {
        int steps = 0;
        while(num1 > 0 && num2 > 0){
            if(num1 >= num2) num1 -= num2;
            else num2 -= num1;

            steps++;
        }

        return steps;

        //      Time Complexity -> O(max(num1,num2))
        //      Space Complexity -> O(1)
}

int main(){

    /*
        Constraints:
            0 <= num1, num2 <= 10^5
    */

    int num1 = 5, num2 = 8;
    cout << countOperations(num1,num2) << endl;

    return 0;
}